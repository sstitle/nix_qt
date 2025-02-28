{
  description = "C++ example flake for Zero to Nix";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
  };

  outputs = { self, nixpkgs }:
    let
      # Systems supported
      allSystems = [
        "x86_64-linux" # 64-bit Intel/AMD Linux
        "aarch64-linux" # 64-bit ARM Linux
        "x86_64-darwin" # 64-bit Intel macOS
        "aarch64-darwin" # 64-bit ARM macOS
      ];

      # Helper to provide system-specific attributes
      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f {
        pkgs = import nixpkgs { inherit system; };
      });
    in
    {
      packages = forAllSystems ({ pkgs }: {
        default =
          let
            binName = "zero-to-nix-cpp";
            cppDependencies = with pkgs; [ cmake gcc ];
          in
          pkgs.stdenv.mkDerivation {
            name = "zero-to-nix-cpp";
            src = ./.;
            buildInputs = cppDependencies;
            installPhase = ''
              mkdir -p $out/bin
              cp ${binName} $out/bin/${binName}
            '';
          };
      });
    };
}
