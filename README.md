IDA Pro Plugin

Fixes incorrect Hex-Rays output for function calls through batch decompilation.

This plugin acts as an alternative hotkey for decompiling the function the cursor is currently in.  Invoking Hex-Rays through this hotkey will first identify all call instructions in the target function, decompile their respective function bodies, then use this information to more accurately decompile the target function.

While testing I found that virtual method calls and exception handlers usually need to be corrected in decompilation.

Currently only supports x86.