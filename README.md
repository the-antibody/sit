# sit
Linux system information tool done in C.

![image](https://user-images.githubusercontent.com/71285258/180618680-e94cb81a-854e-40e6-87ca-e7d60c4a82ce.png)


# About
SIT (system information tool) is an open-source fetching tool that allows you to see the specifications of your individual computer, including the OS and release, and temperature of the parts such as the CPU. SIT is bloat free, memory efficient, fast, and best of all, open source.
 
# Installation
Open a terminal and type these three commands:
```sh
git clone https://github.com/the-antibody/sit
cd sit
sudo make install
```

# Usage
`sudo sit` <br />
(You must be running as root)
 
# Information for Developers
 
### Languages
- C
(With a custom exceptions library built in, view [here](https://github.com/the-antibody/sit/edit/main/src/exceptions.h) if you're worried about bloat)
