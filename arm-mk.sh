
arm-linux-gnueabihf-gcc -o $2 $1 -I/usr/include -I/usr/include/arm-linux-gnueabihf -L/usr/lib/arm-linux-gnueabihf -lglut -lGLU -lGL -lXext -lX11 -lm -ldrm -lxcb-dri2 -lxcb -lXfixes -lXdamage -lxshmfence -lxcb-sync -lxcb-present -lxcb-dri3 -lexpat -lXxf86vm -lxcb-glx -lXau -lX11-xcb -lXdmcp -lglapi -lXi -L/lib/arm-linux-gnueabihf -lbsd -pthread
