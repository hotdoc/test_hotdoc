# -*- coding: utf-8 -*-

class Channel(object):
    """A Channel for notifications.
    Usually not constructed directly, instead it is returned from helper
    functions like new_webhook_channel().
    Attributes:
      type: str, The type of delivery mechanism used by this channel. For
        example, 'web_hook'.
      id: str, A UUID for the channel.
      token: str, An arbitrary string associated with the channel that
        is delivered to the target address with each event delivered
        over this channel.
      address: str, The address of the receiving entity where events are
        delivered. Specific to the channel type.
      expiration: int, The time, in milliseconds from the epoch, when this
        channel will expire.
      params: dict, A dictionary of string to string, with additional parameters
        controlling delivery channel behavior.
      resource_id: str, An opaque id that identifies the resource that is
        being watched. Stable across different API versions.
      resource_uri: str, The canonicalized ID of the watched resource.
    """

    def __init__(self, type, id, token, address, expiration=None,
                   params=None, resource_id="", resource_uri=""):
        """Create a new Channel.
        In user code, this Channel constructor will not typically be called
        manually since there are functions for creating channels for each specific
        type with a more customized set of arguments to pass.
        Args:
          type: str, The type of delivery mechanism used by this channel. For
            example, 'web_hook'.
          id: str, A UUID for the channel.
          token: str, An arbitrary string associated with the channel that
            is delivered to the target address with each event delivered
            over this channel.
          address: str,  The address of the receiving entity where events are
            delivered. Specific to the channel type.
          expiration: int, The time, in milliseconds from the epoch, when this
            channel will expire.
          params: dict, A dictionary of string to string, with additional parameters
            controlling delivery channel behavior.
          resource_id: str, An opaque id that identifies the resource that is
            being watched. Stable across different API versions.
          resource_uri: str, The canonicalized ID of the watched resource.
        """
