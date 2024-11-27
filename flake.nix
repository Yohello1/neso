{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";

  outputs = { self, nixpkgs }:
    let
      inherit (nixpkgs) lib;
      forAllSystems = lib.genAttrs [
        "x86_64-linux"
      ];
    in {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in {
          default = pkgs.mkShellNoCC {
            packages = (with pkgs; [
              qemu
              dtc
              ubootTools
            ]) ++ (with pkgs.pkgsCross.riscv64-embedded.buildPackages; [
              gcc
              gdb
            ]);
          };
        }
      ); 
    };
}
