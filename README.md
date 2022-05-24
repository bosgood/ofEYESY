# ofEYESY

An interface for the [EYESY video synthesizer](https://www.critterandguitari.com/eyesy) that runs modes written in the [Lua programming language](https://www.lua.org/).

Powered by [ofxLua](https://github.com/danomatika/ofxLua).

# Developing

# On the EYESY/Raspberry Pi

Images for the EYESY are built using [pi-gen](https://github.com/RPi-Distro/pi-gen).
While compiling openFrameworks from scratch on the EYESY is likely to fail,
changes to this program can be made in-place once it has been built the first time.

## Local development

1. [Download a copy of openFrameworks](https://openframeworks.cc/download/) for your operating system, and unzip it, noting the directory.
1. Run the following code to set up a data directory for the Lua modes:

    ```console
    mkdir tmp
    TODO [bosgood] Need more steps here
    ```

### Preparation

To compile and run the code on your local machine, follow these steps:

1. From the repo root, run:
    ```console
    # `path-to-of` is the path to the unzipped code downloaded in the previous step
    OF_ROOT=path-to-of make
    ```
1. After compilation, run the code:
    ```console
    EYESY_SHOW_WINDOW=true EYESY_DATA_ROOT=$PWD/tmp make RunRelease
    ```

See the following section for all available configuration settings.

### Configuration settings

The following configuration settings are available via environment variables.

* `EYESY_SHOW_CURSOR` (default `false`) - show the cursor over the video
* `EYESY_DATA_ROOT` (default `/sdcard`) - path to use as a data directory (modes, screen grabs)
* `EYESY_SHOW_WINDOW` (default `false`) - show the video as a window, not fullscreen
* `EYESY_SCREEN_WIDTH` (default `1920`) - in windowed mode, the screen width
* `EYESY_SCREEN_HEIGHT` (default `1080`) - in windowed mode, the screen height
