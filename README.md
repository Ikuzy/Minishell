# Minishell

*This project has been created as part of the 42 curriculum by Ozouine, Iqattami.*

---

# Unix Shell from Scratch

A fully functional Unix shell written in **C**, inspired by **Bash**. Built from the ground up without any shortcuts — every feature from command parsing to signal handling was implemented manually, giving us deep insight into how processes, file descriptors, and the Unix environment actually work.

---

## Description

Minishell is a project from the 42 curriculum that challenges you to build your own shell — a program that reads commands from the user, interprets them, and executes them just like Bash does.

This project required us to deeply understand Unix processes, file descriptor management, signal handling, and memory management in C — with zero tolerance for memory leaks in our own code.

---

## Features

### Command Execution
- Interactive prompt display
- Command history (navigate with arrow keys)
- Executable resolution via `PATH`, relative, or absolute path

### Parsing
- Single quote `'` handling — prevents metacharacter interpretation
- Double quote `"` handling — prevents metacharacter interpretation except for `$`
- Environment variable expansion (`$VAR`)
- `$?` expansion — exit status of the last executed pipeline
- Proper handling of unclosed quotes and unsupported special characters

### Redirections
- `<` — input redirection
- `>` — output redirection
- `>>` — output redirection in append mode
- `<<` — heredoc (reads input until delimiter is reached)

### Pipes
- Full pipeline support (`|`) — output of each command connected to input of the next

### Signals
- `ctrl-C` — displays a new prompt on a new line
- `ctrl-D` — exits the shell
- `ctrl-\` — does nothing (as in Bash)

### Built-in Commands
| Command | Description |
|---------|-------------|
| `echo [-n]` | Print text, `-n` suppresses newline |
| `cd [path]` | Change directory (relative or absolute) |
| `pwd` | Print current working directory |
| `export` | Set environment variables |
| `unset` | Remove environment variables |
| `env` | Print all environment variables |
| `exit` | Exit the shell |

### Memory Management
- Zero memory leaks in our own code
- `readline()` known leaks are excluded per subject specification

---

## Installation & Usage

### Requirements
- Linux or macOS
- `cc` compiler
- `make`
- `readline` library

### Build

```bash
git clone https://github.com/Ozouine/minishell.git
cd minishell
make
```

### Run

```bash
./minishell
```

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files + binary |
| `make re` | Full recompile |

---

## Usage Examples

```bash
# Basic command
minishell$ ls -la

# Pipes
minishell$ cat file.txt | grep "hello" | wc -l

# Redirections
minishell$ echo "hello" > output.txt
minishell$ cat < input.txt >> output.txt

# Heredoc
minishell$ cat << EOF
> hello
> world
> EOF

# Environment variables
minishell$ export NAME=Oussama
minishell$ echo $NAME
Oussama

# Exit status
minishell$ ls nonexistent
minishell$ echo $?
2
```

---

## Technical Choices

- **One global variable only** — used exclusively to store the received signal number, as required by the subject
- **No `readline()` leak fixes** — the subject explicitly allows these; all other memory is properly freed
- **Bash as reference** — any ambiguous behavior was resolved by comparing with Bash's output

---

## Resources

### Shell & Parsing
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell — Tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Shell Command Language — POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

### Processes & File Descriptors
- [Fork, Exec, and Wait — Linux man pages](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Pipe man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [File Descriptors explained](https://www.bottomupcs.com/file_descriptors.xhtml)

### Signals
- [Signal handling in C](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)

### Readline
- [GNU Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html)

---

## Authors

| Login | GitHub |
|-------|--------|
| Ozouine | [@Ikuzy](https://github.com/Ikuzy) |
| Iqattami | [@Qattami](https://github.com/Qattami) |

---

*42 Network — 1337 School Morocco*
