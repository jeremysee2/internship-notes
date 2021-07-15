# Observer Design Pattern Implementation

## Overview

| Type          | Code Size | Added code size | CPU Cycles (10k iterations) |
| ------------- | --------- | --------------- | --------------------------- |
| Async Dynamic | 17,608 B  | + 600 B         | 86,478                      |
| Async List    | 17,256 B  | +248 B          | 88,860                      |
| Async OOP     | 17,408 B  | +400 B          | 97,174                      |
| Sync List     | 17,136 B  | +128 B          | 81,105                      |
| Sync OOP      | 17,344 B  | +336 B          | 83,582                      |
| Sync Simple   | 17,008 B  | 0 B             | 82,103                      |

The CPU cycle counts were measured with the `clock()` function in the `time.h` module. It isn't accurate as there are large variations between runs on my laptop.

The executables are compiled with `gcc` on `x86-64`, for my laptop running Ubuntu 20.04.

The large executable sizes are due to the usage of standard C libraries (`libc`) such as `stdlib` and `stdio`. For embedded environments, pruning can be done to reduce code size. OOP implementations add about `300` bytes to the code size. List implementation vs hardcoding adds about `130` bytes. Asynchronous implementations add about `100` bytes.

## Asynchronous implementations

Asynchronous operation is achieved with queues, used to send messages from the "notifier" to the observer. Synchronous implementations use direct function calls to send messages.

## List implementations

List implementations use a list of direct function pointers/queues to send data. This makes it easy to add additional classes before compilation. Additionally, linked lists can be used to dynamically add/remove observers at runtime.

## OOP implemetation

This uses OOP concepts of encapsulation to move the `observer` object into its separate file. Attributes are implemented in `struct` while operations are separate functions, in the same source file.

## Dynamic implementation

This uses OOP + a linked list to implement a dynamic list of Observers for the Notifier to inform of any updated data.

## Simple implementation

This is traditional direct messaging with global variables, for simple programs.

