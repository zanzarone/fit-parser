{
    "targets": [{
        "target_name": "fit_module",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'CLANG_CXX_LIBRARY': 'libc++',
            'MACOSX_DEPLOYMENT_TARGET': '10.7',
        },
        'msvs_settings': {
            'VCCLCompilerTool': { 'ExceptionHandling': 1 },
        },
        "sources": [
            "<!@(node -p \"require('fs').readdirSync('src/fit/').filter(f=>f.endsWith('.hpp')).map(f=>'src/fit/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/configuration/').filter(f=>f.endsWith('.hpp')).map(f=>'src/configuration/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/fit/').filter(f=>f.endsWith('.cpp')).map(f=>'src/fit/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/tiny-aes/').filter(f=>f.endsWith('.cpp')).map(f=>'src/tiny-aes/'+f).join(' ')\")",
            "<!@(node -p \"require('fs').readdirSync('src/tiny-aes/').filter(f=>f.endsWith('.hpp')).map(f=>'src/tiny-aes/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/nlohmann/').filter(f=>f.endsWith('.cpp')).map(f=>'src/nlohmann/'+f).join(' ')\")",
            "<!@(node -p \"require('fs').readdirSync('src/nlohmann/').filter(f=>f.endsWith('.hpp')).map(f=>'src/nlohmann/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/worker/').filter(f=>f.endsWith('.cpp')).map(f=>'src/worker/'+f).join(' ')\")",
            "<!@(node -p \"require('fs').readdirSync('src/worker/').filter(f=>f.endsWith('.hpp')).map(f=>'src/worker/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/decode/').filter(f=>f.endsWith('.cpp')).map(f=>'src/decode/'+f).join(' ')\")",
            "<!@(node -p \"require('fs').readdirSync('src/decode/').filter(f=>f.endsWith('.hpp')).map(f=>'src/decode/'+f).join(' ')\")",
            # 
            "<!@(node -p \"require('fs').readdirSync('src/encode/').filter(f=>f.endsWith('.cpp')).map(f=>'src/encode/'+f).join(' ')\")",
            "<!@(node -p \"require('fs').readdirSync('src/encode/').filter(f=>f.endsWith('.hpp')).map(f=>'src/encode/'+f).join(' ')\")",
            # 
            "src/main.cc",
            "src/fit_module.hpp",
            "src/fit_module.cpp",
        ],
        'include_dirs': [
            # "<!(node -e \"require('nan')\")",
            # "<!@(node -p \"require('nan').include\")",
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        "libraries": [ ],
        # "libraries": [ "-Wl,-rpath, <(module_root_dir)/src/new_fit/libFitSdkCpp.a" ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        # 'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
