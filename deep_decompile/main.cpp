#include "stdafx.h"

static const char* plugin_name = "Deep Decompile";
static const char* plugin_comment = "Fixes incorrect Hex-Rays output for function calls through batch decompilation.";
static const char* plugin_help_text = "This plugin acts as an alternative hotkey for decompiling the function the \
                                      cursor is currently in.  Invoking Hex-Rays through this hotkey will first \
                                      identify all call instructions in the target function, decompile their \
                                      respective function bodies, then use this information to more accurately \
                                      decompile the target function.";

hexdsp_t *hexdsp = NULL;
static bool inited = false;

// fill 'out' with func_t objects of all called subroutines
void filter_called_functions(func_t* func, std::set<func_t*>& out)
{
    // instruction iteration
    func_item_iterator_t fii;
    for (bool fi_ok = fii.set(func); fi_ok; fi_ok = fii.next_code())
    {
        // xrefs to current instruction iteration
        xrefblk_t xb;
        for (bool ok = xb.first_from(fii.current(), fl_CN); ok; ok = xb.next_from())
        {
            // api bug? have to check xref type or we get jumps with fl_CN flag
            if (xb.iscode && xb.type == fl_CN)
            {
                func_t* toref = get_func(xb.to);
                if (toref)
                    out.insert(get_func(xb.to));
            }
        }
    }
}

void deep_decompile(func_t* target_func)
{
    std::set<func_t*> called_funcs;
    filter_called_functions(target_func, called_funcs);
    for (func_t* cf : called_funcs)
    {
        if (!has_cached_cfunc(cf->startEA))
        {
            hexrays_failure_t hf;
            decompile(cf, &hf);
        }
    }

    open_pseudocode(target_func->startEA, 1);
}

int idaapi init()
{
    if (!init_hexrays_plugin())
        return PLUGIN_SKIP; // no decompiler
    return PLUGIN_OK;
}

void idaapi term()
{
    if (inited)
        term_hexrays_plugin();
}

void idaapi run(int)
{
    func_t* func = get_func(get_screen_ea());
    if (func != nullptr)
        deep_decompile(func);
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

