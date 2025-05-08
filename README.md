# Pipex

Pipex is a project from the 42 curriculum that recreates the shell pipeline behavior, connecting multiple processes through pipes. This project helps deepen your understanding of file descriptors, process creation, and inter-process communication in Unix-like operating systems.

## Features

- Simulates the `|` pipe operator for two commands (MANDATORY).
- Simulates the `|` pipe operator for multiple commands (BONUS).
- Handles input and output redirection.
- Manages errors gracefully.
- Supports environment variables for command execution.
- Provides clear, well-structured code with efficient memory management.

## Installation

Clone the repository and build the project:

```bash
git clone https://github.com/seg-fault0/pipex
cd pipex
make
```

## Usage

The syntax for `pipex` is:

```bash
./pipex file1 cmd1 cmd2 file2
```

- **file1**: Input file.
- **cmd1**: The first command to execute.
- **cmd2**: The second command to execute.
- **file2**: Output file.

Example:

```bash
./pipex input.txt "cat" "grep foo" output.txt
```

This is equivalent to:

```bash
< input.txt cat | grep foo > output.txt
```
