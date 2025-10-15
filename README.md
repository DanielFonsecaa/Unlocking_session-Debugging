# Unlocking Session: Debugging.

Debugging is one of the most essential skills in software development.
This guide covers the fundamentals of using GDB (GNU Debugger) and Valgrind, two powerful tools for finding logic errors, crashes, and memory issues in C and C++ programs.


## 🐞 1. GDB — GNU Debugger

GDB allows you to run your program step by step, inspect variables, set breakpoints, and understand where and why a crash occurs.

### 🔧 Compilation for Debugging
To make debugging effective, you must include **debug symbols** when compiling:
```bash
cc -g3 main.c -o program
```
> The `-g3` flag includes full debugging information (like variable names, line numbers, and macros).

---

### ▶️ Starting GDB
```bash
gdb ./program              # start GDB with your program
gdb --args ./program arg1 arg2  # start GDB with program arguments
```
You can also open a **core dump** file (created when a program crashes):
```bash
gdb ./program core
```

---

### ⏯️ Basic Execution Commands
| Command | Description |
|----------|-------------|
| `run` or `r` | Start the program inside GDB |
| `start` | Run until the first instruction of `main()` |
| `continue` or `c` | Resume execution after a breakpoint |
| `next` or `n` | Execute the next line (don’t enter functions) |
| `step` or `s` | Execute the next line (step into functions) |
| `finish` | Run until the current function returns |
| `quit` or `q` | Exit GDB |

---

### 🎯 Breakpoints
Breakpoints stop your program at specific points for inspection.
```bash
break main               # set a breakpoint at the start of main
break 42                 # set breakpoint at line 42
break file.c:30          # set breakpoint in another file
break function_name      # set breakpoint at the start of a function
info breakpoints         # list all breakpoints
delete 1                 # remove breakpoint number 1
disable/enable 1         # deactivate/reactivate a breakpoint
```

---

### 🔍 Inspecting Program State
| Command | Description |
|----------|-------------|
| `print var` | Print a variable’s value |
| `print *ptr` | Print the value pointed to by a pointer |
| `display var` | Continuously show a variable’s value while stepping |
| `info locals` | Show all local variables in the current function |
| `info args` | Show current function arguments |
| `backtrace` or `bt` | Show the call stack |
| `frame N` | Move to frame number N in the stack |
| `x/10x addr` | Examine 10 hex values from a memory address |
| `info registers` | Display CPU registers |

---

### 💡 Pro Tip
If your program **segfaults**, use:
```bash
gdb ./program core
```
Then inside GDB:
```bash
bt
```
This shows where the crash occurred in your code.

---

## 🧩 2. Valgrind — Memory Debugging Tool

**Valgrind** detects memory leaks, invalid reads/writes, uninitialized memory usage, and more.  
It’s invaluable for ensuring your program manages memory safely.

### ⚙️ Compilation
Valgrind also requires debug symbols:
```bash
gcc -g3 main.c -o program
```

---

### ▶️ Basic Usage
```bash
valgrind ./program
```
This runs your program under Valgrind’s supervision.  
To get more detailed information:
```bash
valgrind --leak-check=full ./program
```

---

### 🔧 Common Flags
| Flag | Description |
|------|--------------|
| `--leak-check=full` | Shows detailed info about each memory leak |
| `--show-leak-kinds=all` | Displays all types of leaks (definite, indirect, etc.) |
| `--track-origins=yes` | Shows where uninitialized values come from |
| `--log-file=valgrind.log` | Saves the output to a file |
| `--track-fds=yes` | Checks for open file descriptor leaks |
| `--error-limit=no` | Shows all errors (no output limit) |

---

### 📊 Example Output
```
==1234== Invalid read of size 4
==1234==    at 0x4005D3: main (main.c:12)
==1234==  Address 0x51f104c is 0 bytes after a block of size 8 alloc'd
==1234==    at 0x4C2FB55: malloc (vg_replace_malloc.c:299)
==1234==    by 0x4005A9: main (main.c:10)
```
This means your program tried to **read memory outside** the allocated range (a buffer overflow or invalid pointer).

---

### 🧼 Memory Leak Example
If you forget to `free()` memory:
```
==5678== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==5678==    at 0x4C2FB55: malloc (vg_replace_malloc.c:299)
==5678==    by 0x4005A9: main (main.c:10)
```
Valgrind tells you **exactly where** the unfreed memory was allocated.

---

## 🧠 Summary
| Tool | Purpose | Key Command |
|------|----------|-------------|
| **GDB** | Step-by-step debugging and inspection | `gdb ./program` |
| **Valgrind** | Detect memory errors and leaks | `valgrind --leak-check=full ./program` |

---

## ✅ Final Tips
- Always compile with `-g3` for maximum debugging information.  
- Use **GDB** for logic and runtime bugs.  
- Use **Valgrind** for memory management issues.  
- Combine both tools for complete debugging coverage.  
- Don’t forget: `printf()` debugging is good — but **GDB** is better.
- -Wall -Wextra -Werror ;p,