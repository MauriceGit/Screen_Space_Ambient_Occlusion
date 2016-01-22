# Screen Space Ambient Occlusion (SSAO)

This project is an implementation of the SSAO algorithm, done completely from scratch.

To take it to the front - I made a video of it in action, where I show different kernel sizes, views and
you can see, what this is all about, pretty good :)

https://vimeo.com/152733656

## What is SSAO?

Screen-space ambient occlusion basically adds some shading/occlusion of areas in the output image where a
real occlusion is suspected. This is done by comparing depth values of the framebuffer just before rendering.
If there are fragments, where pretty much all sides (computed over a local kernel) are closer to the viewer
than the actual fragment, it is assumed, that those fragments are less illuminated then other, more exposed, areas.
In this case, the fragment gets shaded.

This algorithm runs only in screen space. So ignoring the complexity of the scene completely.
That means, that the ambient occlusion is just as fast on a complete scenery than for a simple displayed triangle.

But it also as to be noted, that it is not physically correct and also not always perfect.
So depending on the viewer and camera position, different areas are occluded.

Though not always looking perfect, it adds a very nice touch to the scenery and gives a lot more three dimensional
impressions. It actually looks really good most of the time (Just my opinion).

And adding this screen-space ambient occlusion to a complete game, game engine or random scenery is
really simple. It is basically just one shader which needs to be used after everything else.

So here is a picture of just the final ambient occlusion without actually rendering any colors of the scene:

![Just ambient occlusion](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example5.png "Just ambient occlusion")

And the same view again with normal textures and colors. The ambient occlusion is added:

![Ambient occlusion with normal colors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example6.png "Ambient occlusion with normal colors")

## Install && Run

I only tested an ran this simulation on a debian-based unix OS (Ubuntu, Mint, ...). It should run on any other machine as well but is not
tested.

### **System Requirements**

The following system-attributes are required for running this simulation:

- A graphics card supporting OpenGL version 3.3 (For the shaders).

- Unix-Libraries: xorg-dev, mesa-common-dev and freeglut3-dev

### **Running**

Compiling and running is then pretty straight forward.
It should also work in windows and OSX, but is not tested.
In the root directory, do:

- make
- ./ambient_occlusion

While the simulation runs, you can move around (always looking to the center!) with your mouse (left-klick and move) and zoom in/out with your mouse (right click and move up/down).
All other options for playing around with different kinds of the ambient occlusion (resizing the kernel, ...) are displayed when pressing "h" on your keyboard.

## **More Screenshots**

So, here are some more screenshots, because screenshots are awesome :)

![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example1.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example2.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example3.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example4.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example7.png "Ambient occlusion with different factors")
![Ambient occlusion with different factors](https://github.com/MauriceGit/Screen_Space_Ambient_Occlusion/blob/master/Screenshots/example8.png "Ambient occlusion with different factors")










