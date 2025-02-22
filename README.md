# Pipex

**Pipex** is a project from the 1337 School_42 Network cursus designed to replicate the behavior of the shell's pipe operator. This project allows you to chain commands so that the output of one command becomes the input of another.

## Overview

The objective of Pipex is to simulate the following shell behavior:

```
< file1 cmd1 | cmd2 > file2
```

When executed with:

```
./pipex file1 cmd1 cmd2 file2
```

the program should mimic the shell's handling of piping between commands.

## Features

- **Input Redirection:** Reads from a file.
- **Command Execution:** Executes two commands in sequence.
- **Output Redirection:** Writes the final output to a file.

## Usage

Run the program with exactly four arguments:

```bash
./pipex file1 cmd1 cmd2 file2
```

This command should be functionally equivalent to:

```bash
< file1 cmd1 | cmd2 > file2
```

## Reference

For guidance and in-depth understanding, refer to *The Linux Programming Interface*. In particular, the chapter on **Process Creation** covers essential concepts that are used in this project.

## Project Structure

- **pipex/**: Contains the source code of the Pipex project.
- **pipex_Tests/**: Contains unit tests for the project. For complete end-to-end testing, visit the [Pipex-Tests GitHub repository](https://github.com/AzzaouiAlae/Pipex-Tests).

## Compilation

To compile the project, run:

```bash
make
```

This command builds the project according to the provided Makefile.

