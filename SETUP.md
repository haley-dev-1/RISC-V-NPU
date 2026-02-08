# AI-HDL RISC-V Toolchain Setup (WSL / Ubuntu 22.04)

This document installs and connects the following tools:
- tinyQV (RISC-V CPU + peripherals)
- Yosys (RTL synthesis)
- Verilator (Verilog simulation)
- KLayout (Layout / DRC / LVS)
- OpenROAD (Place & Route)
- OpenLane (RTL → GDSII flow)

Assumptions:
- Windows machine (using Cmd "Command prompt")
- WSL2
- Ubuntu 22.04
- Docker Desktop installed with WSL integration enabled

---

**1. Enter WSL and Create Workspace**
```bash
wsl
mkdir AIHDL
cd AIHDL
```

**2. Clone tinyQV**
```bash
git clone git@github.com:MichaelBell/tinyQV.git
```
OR
```bash
git clone https://github.com/MichaelBell/tinyQV.git
```

**3. Install Yosys for RTL Synthesis**
```bash
sudo apt update
sudo apt-get install gawk git make python3 lld bison clang flex \
	libffi-dev libfl-dev libreadline-dev pkg-config tcl-dev zlib1g-dev \
	graphviz xdot
curl -LsSf https://astral.sh/uv/install.sh | sh
```

**4. Clone and Build Yosys**
```bash
git clone --recurse-submodules https://github.com/YosysHQ/yosys.git
cd yosys
make
sudo make install
make test

mkdir build
cd build
make -f ../Makefile
```

**5. Verilator Installation**
```bash
git clone https://github.com/verilator/verilator   # Only first time
// assuming you're on wsl
unsetenv VERILATOR_ROOT  # For csh; ignore error if on bash
unset VERILATOR_ROOT  # For bash
cd verilator
git pull         # Make sure git repository is up-to-date
git tag          # See what versions exist
#git checkout master      # Use development branch (e.g. recent bug fixes)
#git checkout stable      # Use most recent stable release
#git checkout v{version}  # Switch to specified release version
sudo apt install autoconf

autoconf         # Create ./configure script
./configure      # Configure and create Makefile
make -j `nproc`  # Build Verilator itself (if error, try just 'make')
sudo make install

verilator --version 
# if not showing up, sudo apt install verilator
```

**6. KLayout Installation**
```bash
# you draw your design here. This is for create planning and CTS, IO pads and Pins, pass DRC (Design rule check in Klayout app.)/LVS (comparison between layout and schematic -- are they matching even after you cleared all the DRC errors) runs.
# openlane uses docker to run on a separate openlane dedicated server, the rest of these tools run on local repository
sudo apt update

# ensure you're in your AIHDL directory

sudo apt install klayout

git clone https://github.com/Klayout/klayout.git
cd klayout
./build.sh

klayout --version
klayout # this should pop up a gui... means you're done !
```

**7. OpenROAD**
```bash
# be within AIHDL directory
git clone --recursive https://github.com/The-OpenROAD-Project/OpenROAD.git

# can install with Docker method or local installation.
# filesize isn't too much so we can do local.

sudo apt update
sudo apt install -y libeigen3-dev

./etc/Build.sh

... i had a long fight with ai... make your own fight

./build/bin/openroad # <-- terminal should open 

echo 'export PATH="/mnt/c/Users/haley/AIHDL/OpenROAD/build/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

now i can use openroad to open it

./build/bin/openroad -version # checks version

# /AIHDL/OpenROAD/build/bin$ ./openroad
```

**8. Installing OpenLANE (connects Yosys, OpenROAD, Verilator, KLayout)**
```bash
# Make sure you're in /AIHDL/
1. Open (or install if you don't have it already) Docker Desktop
2. Configure such that it can work with WSL (settings->resources-> etc)
3. verify on wsl by running docker run hello-world

# in AIHDL directory ...
git clone --depth 1 https://github.com/The-OpenROAD-Project/OpenLane.git

cd into OpenLane repo
make
make test

# using docker in OpenLane
make mount

# THE BELOW WILL SHOW KLAYOUT IN EDITING MODE -e WITH SKY130 TECHNOLOGY #
# it is for design phase 4, not now!
##########################################################################
klayout -e -nn $PDK_ROOT/sky130A/libs.tech/klayout/tech/sky130A.lyt \
   -l $PDK_ROOT/sky130A/libs.tech/klayout/tech/sky130A.lyp \
   ./designs/spm/runs/openlane_test/results/final/gds/spm.gds
##########################################################################
```

In Webinar 3 video on YouTube, after all this works, you can work through the example run.

---

**Setting Up for New Phases**

From DP#1 Example Project Run:
```bash
mkdir dpN
# under /tinyQV/ iceFUN and pico_ice are for verification. 
# Cpu and Peripheral files are the required ones.

# in tinyQC full peripheral template/src lives tt_wrapper.v and peripheral.v

git clone https://github.com/TinyTapeout/tinyqv-byte-peripheral-template.git
cd tinyqv- tab
cd src
```

How do I run this?! Use AI to screenshot command prompt log and ask AI for help. 
e.g. in dp1/ copy the contents and say "I want to run synthesis using yosys"

`synth.ys` is the Yosys script we can use to run particular commands.

Then:
```bash
nano synth.ys # we copy ai log into this for our synthesis file

###
### ...
###

yosys -s synth.ys
# or yosys synth.ys

# my peripheral design is synthesizing and working if yosys synth.ys works!
```

Next we run docker module for OpenLane — OpenLane is for PPA analysis:
```bash
~/AIHDL/dp1$ cd ..
~/AIHDL$ cp -r ./dp1 
./OpenLane/designs/

# openlane uses config.json to run a design
```

Back to OpenLane:
```bash
cd AIHDL/OpenLane/
make
make mount # using docker now
./flow.tcl -design dp1 -tag dp1_run -overwrite # command for docker 
# or ./flow.tcl itself
# ./flow.tcl -design dp1
```

Find metrics:
```bash
~/haley/AIHDL/OpenLane/designs/dp1$ cd runs/
~/AIHDL/OpenLane/designs/dp1/runs$ ls
dp1_run
~/AIHDL/OpenLane/designs/dp1/runs/dp1_run$ cd reportS
# Reports should hod the metrics we use for PPA.
```
