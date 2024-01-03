{
  description = "Nix flake for creating dev shells";
  inputs = {
    systems.url = "github:nix-systems/default";
  };

  outputs =
    { systems
    , nixpkgs
    , ...
    } @ inputs:
    let
      eachSystem = f:
        nixpkgs.lib.genAttrs (import systems) (
          system:
          f nixpkgs.legacyPackages.${system}
        );
    in
    {
      devShells = eachSystem (pkgs: {
        default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # Lang tools & deps
            nodejs_18
            nodePackages_latest.node-gyp 
            yarn

            clang_11
            cmake
            cmake-language-server
          ];
          packages = with pkgs; [ python311 virtualenv ] ++
            (with pkgs.python311Packages; [ pip ]);
        };
      });
    };
}
