# Observer Design Pattern Implementation

## Overview

| Type | Code Size | Added code size| CPU Cycles | 
| ---- | --------- | -------------- | ---------- |
| Async List | 17,256 B  | +248 B | |
| Async OOP  | 17,408 B  | +400 B | |
| Sync List  | 17,136 B  | +128 B | |
| Sync OOP   | 17,344 B  | +336 B | |
| Sync Simple | 17,008 B | 0 B    | |

The large executable sizes are due to the usage of standard C libraries such as `stdlib` and `stdio`. For embedded environments, pruning can be done to reduce code size. OOP implementations add about `300` bytes to the code size. List implementation vs hardcoding adds about `140` bytes.

## Asynchronous implementations

Asynchronous operation is achieved with queues, used to send messages from the "notifier" to the observer. Synchronous implementations use direct function calls to send messages.

## List implementations

List implementations use a list of direct function pointers/queues to send data. This makes it easy to add additional classes before compilation. Additionally, linked lists can be used to dynamically add/remove observers at runtime.

## OOP implemetation

This uses OOP concepts of encapsulation to move the `observer` object into its separate file. Attributes are implemented in `struct` while operations are separate functions, in the same source file.

## Simple implementation

This is traditional direct messaging with global variables, for simple programs.

