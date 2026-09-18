This is a wip project

It will allow a user from an image to generate a pattern for pixel art like diy hobbies, like beads, diamond painting, embroidery..

I already have a project like that done with python, check https://github.com/misteurLeu/CraftPatternGenerator to start with it.

This CPP remake will now include an interface under QT, and releases to allow non tech user to use it.

Features TBA:
  - Avaible in the python project:
    - Automatic crop by color/transparency to recenter the image to the main subjet
    - Automatic resize (result depend on the input image, there is no garanty to obtain exploitable result when resizing from 4k image to 50px)
    - Automatic matching and replacement of the original image color to a limited set of colors, the colors can be a set defined by the user, a set get from an online base, or a subset from a previously defined set
    - Full directory process
  - New features :
    -  interfaces with a step by steps user validation
