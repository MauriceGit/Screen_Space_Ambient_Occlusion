# Screen Space Ambient Occlusion (SSAO)

This project is an implementation of a SSAO algorithm, done completely from scratch.

In the following video, the SSAO implementation with different adjustments are demonstrated.

https://vimeo.com/152733656

## What is SSAO?

Screen-space ambient occlusion adds some shading/occlusion of areas in the output image where a
real occlusion is suspected. This is done by comparing depth values of the framebuffer just before rendering.
If there are fragments, where most sides (computed over a local kernel) are closer to the viewer,
the actual fragment, it is assumed to be less illuminated than the surrounding fragments.
In this case, the fragment is shaded.

This algorithm runs only in screen space. So ignoring the complexity of the scene completely.

Any SSAO algorithm is not physically correct and also not always perfect(Bleeding over neighbouring fragments).
Dependent on the viewer and camera position, different areas can be occluded.

Though not always looking perfect, it adds a very nice touch to the scenery and gives a three dimensional
impression.

By adding the SSAO fragment shader to a finished game or program, screen space ambient occlusion can be
adjusted and implemented without changing or accessing the actual code.

The following picture shows the final ambient occlusion without rendering any colors of the scene:

![Just ambient occlusion](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example5.png "Just ambient occlusion")

And the same view again with normal textures and colors. The ambient occlusion is added (multiplied to the fragment color):

![Ambient occlusion with normal colors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example6.png "Ambient occlusion with normal colors")

## Install && Run

I tested an ran this simulation on a debian-based Linux OS (Ubuntu, Mint, ...). It should run on other machines as well but is not
tested.

### System Requirements

The following system-attributes are required for running this simulation:

- A graphics card supporting OpenGL version 3.3 (For the shaders).

- Unix-Libraries: xorg-dev, mesa-common-dev and freeglut3-dev

### Running

It should work on Windows and OSX, but is not tested.
In the root directory, execute:

- make
- ./ambient_occlusion

While the simulation runs, you can move around (always looking to the center!) with your mouse (left-klick and move) and zoom in/out with your mouse (right click and move up/down).
All other options for playing around with different kinds of the ambient occlusion (resizing the kernel, ...) are displayed when pressing "h" on your keyboard.

## Improvements

Some possible improvements I could think of right now, are:

- Implementation of a random kernel for each fragment (persistent) to minimize bleeding over neighbouring fragments.
- Normalization of the occlusion-factor to not get fragments blacked out completely.

## More Screenshots

So, here are some more screenshots, because screenshots are awesome :)

![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example1.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example2.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example3.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example4.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example7.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example8.png "Ambient occlusion with different factors")










