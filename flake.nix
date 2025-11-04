{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };
  outputs = {nixpkgs, ...}: let
    pkgsLinux = import nixpkgs { system = "x86_64-linux"; };
  in {
      devShells."x86_64-linux".default = pkgsLinux.mkShell.override { stdenv = pkgsLinux.llvmPackages_19.stdenv; } {
        system = "x86_64-linux";
        packages = with pkgsLinux; [ 
          ninja
          cmake
          gdb
        ];
      };
    };
}
