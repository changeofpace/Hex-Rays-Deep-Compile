# Deep Decompile

## Summary

An IDA Pro Plugin.

This plugin improves Hex-Rays output for a target function by decompiling all functions called by the target function before decompiling the target function.

## Building

- Use the **"32 Release"** and **"64 Release"** solution configurations.  Note that 64-bit IDA plugins are compiled to the Win32 platform.
- A post-build event requires the **"IDA_PATH"** environment variable to be defined to IDA's installation directory.

## Output comparison

See **deep_decompile_output.cpp** and **hexrays_output.cpp**.