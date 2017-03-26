---
symbols:
    - org.test.greeter.CompletedGreet
    - org.test.greeter.Greet
title: Simple title
short-description: simple short description
...

This page is just here to test symbol ordering, even though [](org.test.greeter.Greet) comes first in the xml source, it should come after [](org.test.greeter.CompletedGreet) here, if it does not that is a bug. I am also referencing [this page](python-index) for good measure.

The other symbols are implicitly listed, as this file is named after the source file.
