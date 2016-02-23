# -*- coding: utf-8 -*-

"""
A random short description.

And a random, not really longer one.
"""

def my_module_level_function(an_arg, another_arg):
    """A module-level function

    This is really just a simple function.

    Arguments:
        an_arg: bool, just an argument
        another_arg: dict, just another argument
    """

class AClass(object):
    """A class.

    It's really just a class.

    Attributes:
        my_int_attribute: int, an integer attribute
        my_outside_init_int_attribute: int, an integer attribute
            defined outside the __init__ function.
    """

    def __init__(self, an_arg):
        """Construct an instance of AClass.

        Doesn't really do much more.

        Arguments:
            an_arg: str, just an argument, not really used.
        """
        self.my_int_attribute = 38

    def simple_function(self, an_arg):
        """
        Simple doc for a simple function.

        Linking to :class:`AClass` though.
        Linking to it real hard `python_example.AClass`

        This also defines an attribute outside of `__init__`,
        bad style but what can you do?

        Arguments:
            an_arg: str, just an arg, not really used.

        Returns:
            int: A random int
        """
        self.my_outside_init_int_attribute = 38
        return 42 
