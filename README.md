
# Developing kernel modules on NixOS

On a NixOS machine with a single channel you can run:

```
$ nix-shell '<nixpkgs>' -A linux.dev
$ make -C $(nix-build -E '(import <nixpkgs> {}).linux.dev' --no-out-link)/lib/modules/*/build M=$(pwd) modules
make: Entering directory '/nix/store/2bfdc7x7mkrwrid6njl4ha6pq9dz7h1s-linux-4.19.80-dev/lib/modules/4.19.80/build'
  CC [M]  /home/ghibe/code/kernel_module/hello.o
  Building modules, stage 2.
  MODPOST 1 modules
WARNING: modpost: missing MODULE_LICENSE() in /home/ghibe/code/kernel_module/hello.o
see include/linux/module.h for more information
  CC      /home/ghibe/code/kernel_module/hello.mod.o
  LD [M]  /home/ghibe/code/kernel_module/hello.ko
make: Leaving directory '/nix/store/2bfdc7x7mkrwrid6njl4ha6pq9dz7h1s-linux-4.19.80-dev/lib/modules/4.19.80/build'
$ dmesg -C # clean kernel log
$ sudo insmod hello.ko # load module into kernel
$ dmesg
```
