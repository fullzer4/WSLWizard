{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = with pkgs; [
    yarn
    nodejs
    nodePackages_latest.node-gyp
    ninja
  ];
}
