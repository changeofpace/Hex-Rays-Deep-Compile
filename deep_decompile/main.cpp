#include "stdafx.h"
#include <Windows.h>

hexdsp_t* hexdsp = NULL;

namespace {
////////////////////////////////////////////////////////////////////////////////
// plugin description

const char* plugin_name = "Deep Decompile";
const char* plugin_comment = "Improves Hex-Rays output through batch decompilation.";
const char* plugin_help_text = "This plugin improves Hex-Rays output for a target function by decompiling all functions called by the target function before decompiling the target function.";

bool plugin_initialized = false;

////////////////////////////////////////////////////////////////////////////////
// implementation

void get_called_functions(func_t* target_func, std::unordered_set<func_t*>& called_funcs)
{
    func_item_iterator_t fii;
    for (bool fi_ok = fii.set(target_func); fi_ok; fi_ok = fii.next_code())
    {
        xrefblk_t xb;
        for (bool ok = xb.first_from(fii.current(), XREF_ALL); ok; ok = xb.next_from())
        {
            if (xb.iscode && (xb.type == fl_CN || xb.type == fl_CF))
            {
                func_t* toref = get_func(xb.to);
                if (toref && toref != target_func)
                    called_funcs.insert(toref);
            }
        }
    }
}

void deep_decompile(func_t* target_func)
{
    if (!target_func)
        return;
    std::unordered_set<func_t*> called_funcs;
    get_called_functions(target_func, called_funcs);
    for (auto func : called_funcs)
    {
        if (!has_cached_cfunc(func->startEA))
        {
            hexrays_failure_t hf;
            decompile(func, &hf);
        }
    }
    open_pseudocode(target_func->startEA, 1);
}

} // namespace

////////////////////////////////////////////////////////////////////////////////
// plugin exports

int idaapi init()
{
    if (!init_hexrays_plugin())
        return PLUGIN_SKIP;
    plugin_initialized = true;
    msg("Deep Decompile loaded.\n");
    return PLUGIN_OK;
}

void idaapi term()
{
    if (plugin_initialized)
        term_hexrays_plugin();
}

void idaapi run(int)
{
    deep_decompile(get_func(get_screen_ea()));
}

plugin_t PLUGIN =
{
    IDP_INTERFACE_VERSION,
    PLUGIN_KEEP,
    init,                   // initialize
    term,                   // clean up before exiting
    run,                    // invoke plugin
    plugin_name,
    plugin_help_text,
    plugin_name,            // name that appears in the plugins list
    NULL                    // preferred hotkey
};

