# C++ Programming Exercise

## Instructions

Produce a small working application for review by your prospective employer, the
details of the application are provided below.

The aim for the test is to understand how you structure your solution, and how
well you manage to turn that solution into a working application.

You need to:

 * Produce working Object Orientated, unit-tested code.
 * Provide instructions on running and building your application.
 * Deliver the working application to your prospective employer.

You are expected to complete the test alone without immediate help, however
should you have any questions or need more clarity then contact via Github
either by raising an issue or messaging directly.

You are not expected to know all the technologies used in this exercise, however
you should be able to find information on the internet.

There is no given time limit, however the test is designed to be short.  Please
read the entire brief and then contact the person who gave you this assignment
if you feel you are unable to complete the task in the allotted time frame.

## The Assignment

Before you begin to write your solution, you should first fork this repository.
Provide a link to your forked repository to the person who gave you this
exercise.  You should (as with any project) commit and push regularly to your
forked repository.

The solution should be written in C++.

A boilerplate project has been provided as part of the repository.  Candidates
are encouraged to use the provided framework as the basis of their project.

The boilerplate project makes use of and uses the following dependencies:

 * CMake
 * googletest
 * git

A `Vagrantfile` has been provided, it can optionally be used to build the
project using Centos 6.

If any of the above software is unknown to you, then you are expected to
research the subjects yourself, factor this in to the estimate you give to
complete this task.

The project has been designed with Cross-platform support in mind.  Ensure that
your software builds and runs on at minimum `Centos 6`, and preferably
`Windows 2008 r2 or greater` and/or `Mac OS 10`.

Efforts should be made maintain support for the following platforms:

 * Windows 2008 r2 or greater
 * Centos 6 or other linux
 * Mac OS 10

We do not expect that you may have access to all of the OS platforms listed
above.  Should you be unable to test on all of the above platforms make a note
of this fact here: [modify this]

The goal of this exercise is to produce a reusable library which provides basic
calculator functions.

The calculator library should have methods for the following functionality:

 * Add a value
 * Subtract a value
 * Multiply by a value
 * Divide by a value
 * A method to return the total
 * An undo method

The library should have written tests, but also a simple console application
which demonstrates the library should also be provided.

The application should:

 * Accept operations from stdin
 * Print to stdout the running total
 * a command to display the command history
 * a command to undo
 * a command to clear/restart

Documentation on both the library and the console application should be
included.

## Building the boilerplate project

### Linux / MacOS

The following commands will build on linux:

```
mkdir build
cd build
cmake ../
make
make test
```

This project requires googletest, googletest can be installed system-wide or
locally, if installed locally set the `GTEST_ROOT` variable to the install
location of googletest.

Note that the supplied Vagrantfile will build a linux VM and provision it for
building the project.

### Windows

There are various ways to build on windows.  This project has been tested using
MS Visual Studio Express 2010.  Using other versions of Visual Studio and other
Generators should work fine as well.

Download and install CMake make sure it is in your PATH.

Download and unpack Google Test to `c:\googletest`

Build googletest from the `Visual Studio Command Prompt (2010)`:

```
cd c:\googletest
cmake ./ -G "NMake Makefiles"
nmake
```

The CMake variable `GTEST_ROOT` can be configured should googletest be installed
in a different location.

To build this project still from the `Visual Studio Command Prompt (2010)`:

```
cd c:\<location of this repo>
mkdir build
cd build
cmake ../ -G "NMake Makefiles"
nmake
nmake test
```

