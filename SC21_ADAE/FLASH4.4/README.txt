
# Set up for FLASH simulations 
cd /path/to/FLASH4.4

./setup Sedov -auto -3d +noio
./setup Cellular -auto -3d +noio
./setup StirTurb -auto -3d -maxblocks=200 -nxb=32 -nyb=32 -nzb=32 +noio
