{
    "targets": [{
        "target_name": "FITParser",
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
            "src/fit_parser.hpp",
            "src/fit_parser.cpp",
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        "libraries": [ ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
    }]
}
