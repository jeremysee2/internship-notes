# Internship Notes

Notes about NB-IoT and UML for software design.

## Notes

architectural design patterns
linked to OOP

software design
one component, other components want to know what its doing (get notified)
- observer design pattern

create software components that implement these patterns, lightweight (memory and power, C)

look up design patterns, think about which of them relevant to embedded, protocol stack for wireless comms,
- architectural MVC design pattern (UI)
- which ones are relevant/applicable????
- in C, not C++

Asynchronous and synchronous components.
Communicate by sending messages, not be direct function calls. For suitability in RTOS environments, to prevent concurrency issues.
Look for patterns, as they relate to C, and embedded systems with constrained memory, in an RTOS environment
List all design patterns with brief description
Pick a few
Dig deeper (synchronous, asynchronous multi-threaded, dynamic registration, more lightweight, differences in code sizes etc.)

[Good book on Object Oriented C](https://planetpdf.com/codecuts/pdfs/ooc.pdf)


## Questions:

OOP seems to use a lot of dynamic allocation (instantiation, polymorphism), how to implement that in an embedded environment?

in the context of a network stack, seems that pipelining is the main strategy. Using layered architecture (OSI model).
As the variety of protocols expand, start to use Component Based Architecture (like hexagonal etc.)