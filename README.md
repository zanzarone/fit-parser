<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/zanzarone/fit-parser">
    <img src="res/logo1.png" alt="Logo">
  </a>

  <p align="center">
    A simple and useful parser for decoding/encoding FIT files.
    <br />
    <!-- <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a> -->
    ·
    <a href="https://github.com/zanzarone/fit-parser/issues">Report Bug</a>
    ·
    <a href="https://github.com/zanzarone/fit-parser/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Overview</a></li>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->

## About The Project

A simple and useful Node.js tool written in C++/JS using Node-API for decoding/encoding FIT files.

<!-- GETTING STARTED -->

## Getting Started

To compile the add-on you need a toolchain that compile C and C++ code into binaries.

### Prerequisites

**Node.js**

The NodeJS ecosystem is mandatory and can be installed downloading the binaries for your architecture, [here](https://nodejs.org/en/).

**node-gyp**

After developing process, to correctly deploying the addon, you need `node-gyp` build system installed.
You can find all the information needed, [here](https://github.com/nodejs/node-gyp).

---

**Linux**

For Linux, a proper C/C++ compiler toolchain, like [GCC](https://gcc.gnu.org).

---

**macOS**

For macOS, install XCode Command Line Tools which will install clang, clang++, and make:

```
xcode-select --install
```

---

**Windows**

For Windows the build tools system is now shipped with Node.js.

### Installation

To install the others development packages, simply type into the terminal:

```
npm install
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Project structure

The core of the addon resides within the **src** folder and it is structured like below:

- ![a](res/icons8-directory-16.png) **configuration** - utility functions and defines.
- ![a](res/icons8-directory-16.png) **decode** - C++ class to decode FIT file.
- ![a](res/icons8-directory-16.png) **encode** - C++ class to encode FIT file.
- ![a](res/icons8-directory-16.png) **fit** - source code of the FIT SDK.
- ![a](res/icons8-directory-16.png) **nlohmann** a wonderful C++ class for handle JSON objects. More information at [nlohmann/json](https://github.com/nlohmann/json).
- ![a](res/icons8-directory-16.png) **worker** - the async N-API C++ class for schedule the parsing process to the background avoiding Node's main loop.
- ![a](res/icons8-file-16.png) **fit_parser.cpp/fit_parser.hpp** - N-API wrapper class that expose all the addon functionalities.
- ![a](res/icons8-file-16.png) **main.cpp** - The entry point of the module.

**Note:** Files in the **fit** folder are sourced from the FIT SDK. If you have custom generated messages, you'll need to replace the files within this folder with your own.

<!-- USAGE EXAMPLES -->

### Build

After the installation step you can build the addon module with the following command:

```
npm run build
```

The command will produce the binary file for the current platform inside **binary** folder.

**Other commands**

- To build and then run the test, use:

  ```
  npm run build+
  ```

- To rebuild(clean + build):

  ```
  npm run rebuild
  ```

- To rebuild and then run the test:

  ```
  npm run rebuild+
  ```

- To simply clean:

  ```
  npm run clean
  ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Pre/Post Scritps

Contents of the **scripts** folder:

- `post.js` - for moving the compiled module in the convenient folder **binary**.

<!-- USAGE EXAMPLES -->

## Usage

### Include the module

```js
const fitModule = require("<your path>/FITParser.node");
```

### ![a](res/icons8-upload-16-2.png) Decode from file path

```js
fitModule.decodeFile("filepath", [options], (err, result) => ...)
```

Params:

| Name     |           Mandatory           | Type         | Descriptions                          |
| -------- | :---------------------------: | ------------ | ------------------------------------- |
| filepath | ![a](res/icons8-done-16.png)  | _String_     | filepath of the FIT file to decode    |
| options  | ![a](res/icons8-close-16.png) | _JSON array_ | see [decode options](#decode-options) |
| callback | ![a](res/icons8-done-16.png)  | _Function_   | the callback function                 |

Callback params:

| Name   | Type          | Descriptions                                                                |
| ------ | ------------- | --------------------------------------------------------------------------- |
| err    | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_ |
| result | _JSON string_ | the JSON string representing the FIT file                                   |

### ![a](res/icons8-upload-16-2.png) Decode from buffer

```js
fitModule.decodeBuffer(buffer, [options], (err, result) => ...)
```

Params:

| Name     |           Mandatory           | Type         | Descriptions                            |
| -------- | :---------------------------: | ------------ | --------------------------------------- |
| buffer   | ![a](res/icons8-done-16.png)  | _Buffer_     | buffer object of the FIT file to decode |
| options  | ![a](res/icons8-close-16.png) | _JSON array_ | see [decode options](#decode-options)   |
| callback | ![a](res/icons8-done-16.png)  | _Function_   | the callback function                   |

Callback params:

| Name   | Type          | Descriptions                                                                |
| ------ | ------------- | --------------------------------------------------------------------------- |
| err    | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_ |
| result | _JSON string_ | the JSON string representing the FIT file                                   |

---

### ![a](res/icons8-upload-16-2.png) Decode options

All the available decode options are listed below:

| Option name | Type               | Default     | Description                                                                                                         |
| ----------- | ------------------ | ----------- | ------------------------------------------------------------------------------------------------------------------- |
| skipHeaders | _bool_             | _false_     | if true, messages's header is skipped                                                                               |
| force       | _bool_             | _false_     | if true, the decode process continue even if an incomplete stream is found                                          |
| rawValues   | _bool_             | _false_     | if true, all fields will be produced with the .FIT _internal_ representation: `{value:..., offset:..., scale:...,}` |
| include     | _Array of numbers_ | _undefined_ | An array of message's id<sup>1</sup> representing **only** the messages that will be included in the decoded result |
| exclude     | _Array of numbers_ | _undefined_ | An array of message's id<sup>1</sup> representing the messages to be excluded from decoded result                   |
| version     | _int_              | 2           | Protocol version of the FIT library                                                                                 |

id<sup>1</sup>: All message _ids_ can be retrieved from property `defines` of `fitModule` object like below:

```js
fitModule.defines.FILE_ID; // = 0
fitModule.defines.FILE_CREATOR; // = 1
...
```

The complete list is visible in the header ![a](res/icons8-file-16.png) `fit_profile.hpp`.

### ![a](res/icons8-parallel-workflow-16.png) Async/Await

All the decode/encode functions above, have the corresponding _awaitable_ version using the suffix **Async**:

```js
try {
  const result = await fitModule.decodeBufferAsync(...);
  const fit = JSON.parse(result);
  ...
} catch (err) {
  ...
}
```

In folder ![a](res/icons8-directory-16.png) **example** there are different types of FIT files you can choose to test the module.

### ![a](res/icons8-download-16-2.png) Encode JSON string

```js
fitModule.encodeJsonToFile("filepath", jsonString, [options], (err, result) => ...)
```

Params:

| Name       |           Mandatory           | Type         | Descriptions                                                  |
| ---------- | :---------------------------: | ------------ | ------------------------------------------------------------- |
| filepath   | ![a](res/icons8-done-16.png)  | _String_     | representing the path where the file will be saved            |
| jsonString | ![a](res/icons8-done-16.png)  | _String_     | stringified JSON object represent the .FIT file to be written |
| options    | ![a](res/icons8-close-16.png) | _JSON array_ | see [encode options](#encode-options)                         |
| callback   | ![a](res/icons8-done-16.png)  | _Function_   | the callback function                                         |

Callback params:

| Name | Type          | Descriptions                                                                               |
| ---- | ------------- | ------------------------------------------------------------------------------------------ |
| err  | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_                |
| info | _JSON array_  | a JSON array containing warnings<sup>**1**</sup>(JSON object composed by _message_/_code_) |

Warnings<sup>**1**</sup>: array not empty, means there is something in `fitObj` that is not ok but the .fit file will still be produced.

### ![a](res/icons8-download-16-2.png) Encode buffer

```js
fitModule.encodeBuffer("filepath", buffer, [options], (err, result) => ...)
```

Params:

| Name     |           Mandatory           | Type         | Descriptions                                       |
| -------- | :---------------------------: | ------------ | -------------------------------------------------- |
| filepath | ![a](res/icons8-done-16.png)  | _String_     | representing the path where the file will be saved |
| buffer   | ![a](res/icons8-done-16.png)  | _Buffer_     | the Buffer object of the FIT file to encode        |
| options  | ![a](res/icons8-close-16.png) | _JSON array_ | see [encode options](#encode-options)              |
| callback | ![a](res/icons8-done-16.png)  | _Function_   | the callback function                              |

Callback params:

| Name | Type          | Descriptions                                                                                      |
| ---- | ------------- | ------------------------------------------------------------------------------------------------- |
| err  | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_                       |
| info | _JSON array_  | a JSON array containing warnings<sup>**1**</sup> object(JSON object composed by _message_/_code_) |

Warnings<sup>**1**</sup>: array not empty, means there is something in `fitObj` that is not ok but the .fit file will still be produced.

### ![a](res/icons8-download-16-2.png) Encode options

All the available decode options are listed below:

| Option name | Type               | Default     | Description                                                                                |
| ----------- | ------------------ | ----------- | ------------------------------------------------------------------------------------------ |
| exclude     | _Array of numbers_ | _undefined_ | An array of message's id<sup>1</sup> representing the messages to be skipped from encoding |
| version     | _int_              | 2           | Protocol version of the FIT library                                                        |

id<sup>1</sup>: All message _ids_ can be retrieved from property `defines` of `fitModule` object like below:

```js
fitModule.defines.FILE_ID; // = 0
fitModule.defines.FILE_CREATOR; // = 1
...
```

The complete list is visible in the header ![a](res/icons8-file-16.png) `fit_profile.hpp`.

## Exported Defines

To access the defines

```js
fitModule.defines.VERSION;
fitModule.defines.FIT_BASE_TYPES;
fitModule.defines.FIT_FILE_TYPES;
fitModule.defines.FIT_MESG_NUM;
fitModule.defines.SYSTEM_TIME_OFFSET_SEC;
```

```c
  #define VERSION <current version>
  #define SYSTEM_TIME_OFFSET_SEC 631065600
  #define LEFT_RIGHT_BALANCE_100 100.0

  #define FIT_ENUM_INVALID            ((FIT_ENUM)0xFF)
  #define FIT_SINT8_INVALID           ((FIT_SINT8)0x7F)
  #define FIT_UINT8_INVALID           ((FIT_UINT8)0xFF)
  #define FIT_SINT16_INVALID          ((FIT_SINT16)0x7FFF)
  #define FIT_UINT16_INVALID   ((FIT_UINT16)0xFFFF)
  #define FIT_SINT32_INVALID   ((FIT_SINT32)0x7FFFFFFF)
  #define FIT_UINT32_INVALID   ((FIT_UINT32)0xFFFFFFFF)
  #define FIT_STRING_INVALID   ((FIT_STRING)0x00)
  #define FIT_FLOAT32_INVALID   ((FIT_FLOAT32)*((FIT_FLOAT32*)::fit::baseTypeInvalids[FIT_BASE_TYPE_FLOAT32 & FIT_BASE_TYPE_NUM_MASK]))
  #define FIT_FLOAT64_INVALID   ((FIT_FLOAT64)*((FIT_FLOAT64*)::fit::baseTypeInvalids[FIT_BASE_TYPE_FLOAT64 & FIT_BASE_TYPE_NUM_MASK]))
  #define FIT_UINT8Z_INVALID   ((FIT_UINT8Z)0x00)
  #define FIT_UINT16Z_INVALID   ((FIT_UINT16Z)0x0000)
  #define FIT_UINT32Z_INVALID   ((FIT_UINT32Z)0x00000000)
  #define FIT_BYTE_INVALID   ((FIT_BYTE)0xFF)
  #define FIT_SINT64_INVALID   ((FIT_SINT64)0x7FFFFFFFFFFFFFFFL)
  #define FIT_UINT64_INVALID   ((FIT_UINT64)0xFFFFFFFFFFFFFFFFL)
  #define FIT_UINT64Z_INVALID   ((FIT_UINT64Z)0x0000000000000000L)

  #define FIT_FILE_INVALID     0xFF
  #define FIT_FILE_DEVICE      ((FIT_FILE)1)
  #define FIT_FILE_SETTINGS    ((FIT_FILE)2)
  #define FIT_FILE_SPORT       ((FIT_FILE)3)
  #define FIT_FILE_ACTIVITY    ((FIT_FILE)4)
  #define FIT_FILE_WORKOUT     ((FIT_FILE)5)
  #define FIT_FILE_COURSE      ((FIT_FILE)6)
  #define FIT_FILE_SCHEDULES   ((FIT_FILE)7)
  #define FIT_FILE_WEIGHT      ((FIT_FILE)9)
  #define FIT_FILE_TOTALS      ((FIT_FILE)10)
  #define FIT_FILE_GOALS       ((FIT_FILE)11)
  #define FIT_FILE_BLOOD_PRESSURE ((FIT_FILE)14)
  #define FIT_FILE_MONITORING_A   ((FIT_FILE)15)
  #define FIT_FILE_ACTIVITY_SUMMARY   ((FIT_FILE)20)
  #define FIT_FILE_MONITORING_DAILY   ((FIT_FILE)28)
  #define FIT_FILE_MONITORING_B       ((FIT_FILE)32)
  #define FIT_FILE_SEGMENT            ((FIT_FILE)34)
  #define FIT_FILE_SEGMENT_LIST       ((FIT_FILE)35)
  #define FIT_FILE_EXD_CONFIGURATION  ((FIT_FILE)40)
  #define FIT_FILE_MFG_RANGE_MIN      ((FIT_FILE)0xF7)
  #define FIT_FILE_MFG_RANGE_MAX      ((FIT_FILE)0xFE)
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Attributions

All logo/icons of the project are provided by [Icon8](https://icons8.com).
