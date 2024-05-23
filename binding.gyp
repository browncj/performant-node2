{
  "targets": [
    {
      "target_name": "addon",
      "cflags": [
        "-fexceptions"
      ],
      "cflags_cc": [
        "-fexceptions"
      ],
      "sources": [
        "./src/app.cpp"
      ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include_dir\")",
        "/opt/homebrew/Cellar/boost/1.85.0/include"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "xcode_settings": {
        "OTHER_CFLAGS": [
          "-fexceptions"
        ],
        "OTHER_CPLUSPLUSFLAGS": [
          "-fexceptions"
        ]
      },
      "msvs_settings": {
        "VCCLCompilerTool": {
          "ExceptionHandling": 1
        }
      }
    }
  ]
}
