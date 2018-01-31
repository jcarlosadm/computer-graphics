# computer-graphics
Repository for the Computer Graphics course

## How install opengl

```
sudo apt install libdrm2 mesa-common-dev
sudo apt install linux-headers-`uname -r`
sudo apt install libxi-dev libxmu-dev x11proto-xf86vidmode-dev
sudo apt install git-core autoconf automake libtool
sudo apt install freeglut3 freeglut3-dev
```

## How setup Sublime Text

Go `Tools > Build System > New Build System...`

Paste the following code:

```
{
    "cmd": [ "g++ \"$file\" -o \"$file_base_name\" -lGLU -lGL -lglut && ./\"$file_base_name\""],
    "working_dir": "${project_path:${folder}}",
    "selector": ["source.c++"],
    "shell": true
}
```

Save as `opengl.sublime-build`

Select build system. Create a c code. Build with `ctrl b`.