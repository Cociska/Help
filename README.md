# my_sudo

`my_sudo` is a simplified, student-friendly re-implementation of the basic behavior of the Unix `sudo` command.  
Its goal is **not** to replace the real `sudo`, but to demonstrate how privilege checking, argument parsing, and helper messages can be implemented in C.

## Features
- Basic command-line parsing
- Support for the `-h` `-g` `-u` flag
- Clean and modular C code organization
- Unit tests for the help flag

## Repository Structure
```
.
├── include
│   └── my_sudo.h
├── Makefile
├── README.md
├── src
│   ├── help.c
│   ├── parsing.c
|   └── main.c
└── tests
    └── test_h_flag.c
```

## Build & Run
### Build
```
make
```

### Run
```
./my_sudo [options]
```

### Help
```
./my_sudo -h
```