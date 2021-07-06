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

[Good book on Object Oriented C](https://planetpdf.com/codecuts/pdfs/ooc.pdf)


## Questions:

OOP seems to use a lot of dynamic allocation (instantiation, polymorphism), how to implement that in an embedded environment?

in the context of a network stack, seems that pipelining is the main strategy. Using layered architecture (OSI model).
As the variety of protocols expand, start to use Component Based Architecture (like hexagonal etc.)