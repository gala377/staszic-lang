# Project setup

This lesson solely focuses on the examplary C++ project template.

## Version Control System

TODO -
    git overview/
    github/bitbucket
    simple commands - status, add, commmit, push, pull, branch (later)
    gitignore

## Build System

Some languages like [Rust](TODO_hyperlink) or [Go](TODO_hyperlink) have
tools for project managment already bundled up with their installation.
Other like C++ or [Haskell](TODO_hyperlink) only come with their compiler
(C++ doesn't even have official compiler, it's just that [`gcc`](TODO_hyperlink)
is the default compiler on linux systems), which allows
to compile single files to library or executable files and link alongside them.
Which, mind you, is sufficient, but at the same time leaves the user
with the gruesome task of manually specyfing all the files in the working tree
and managing all the dependencies.

For one, two-file projects that alone might be fine, but for any more
complicated project, which might be extended later, a proper build system is required.

### What is a build system

A build system lifts project managment to higher abstraction layer.
For build system to work, usually, user needs to write special
configuration files which build system reads and then, based on them calls compiler,
links dependencies, decides on compilation flags, creates different
binaries (for example debug executable, without optymalizations and
with logs on or test executable which runs program tests).

It is conveniant as user now only needs to write short and simple commands
as well as can build several targets at the same time. What's more it's
also possible to specify complicated build relations, like compiling
main target only if all of the software tests passed.

You may ask ["tests?"](hyperlink_to_wiki), ["build targets"](hyperlink_to_wiki)...
and so on. Google hold answers to all of theese questions, as well as this and
later lessons in this course.

### Our build system

As said before C++ doesn't come with build system.
However there are some which can be considered popular.
Popularity of the tool alone is important as it ensures that if any problem,
and there will be problems, might occur, finding help won't be a challenge in itself.

For this course we'll use [`CMake`](TODO_heprlink). For Linux CMake generates
`MakeFiles` which are then used by the program [`make`](TODO_hyperlink) to build
the whole project. So theese two will be necessary to proceed.

### Prequisitions

As said above there are some things we need to ensure to have installed.

* C++ compiler. Examples will use clang 9.0.0 but gcc is also a valid option
on linux. On Windows there is MSVC, however as all of the examples
it this course are prepared on linux using Windows for this course is discouraged.
What's more this course will use C++17 features so it's importat
to ensure that the chosen compiler supports them in the version
you have installed.
* C++ IDE supporting CMakeLists. Not necessary but would really help.
[`Clion`](todo_hyperlink) does the trick and is free for students.
For free alternative `VSCode` with `clangd`, `CMake` and `CMake Tools` extensions
with generated `compile_commands.json` file works fine as well.

* CMake- TODO
* Make - TODO

the rest is considered TODO

### Project structure

## Reasources

todo

* make,
* cmake,
* cmake tutorial,
* clang,
* gcc,
* msvc,
* git,
* git book,
* github,
* bitbucket,