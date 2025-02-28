# nix_qt

This is an example showing how you can run a simple C++ Qt application using Nix! It uses a Nix flake and can be run:

```bash
nix --extra-experimental-features "nix-command flakes" run github:sstitle/nix_qt
```

## Install Nix 

Install Nix using the [determinate installer](https://github.com/DeterminateSystems/nix-installer): 

```bash
curl --proto '=https' --tlsv1.2 -sSf -L https://install.determinate.systems/nix | \
  sh -s -- install
```

## Build and Run

```bash
nix run .
nix run . -- --help
```
