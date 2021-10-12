# Embedded Device Example

For my example of an embedded device I chose the Xbox Controller.  This device contains a micro controller with limited
storage flash storage and various input sensors. The sensors measture the movement of thumb sticks and detect button presses.
All of this information is transmitted wirelessly or using a wired USB connection to an XBox gaming system.

The XBox Controller faces numerous design challenges.  First, this type of embedded system must provide responsive measurement
in real-time. The data must be rapidly transferred to the XBox Game system or else user experience can be affected. The controller 
also allows 