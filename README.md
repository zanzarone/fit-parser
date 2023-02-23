# ![a](res/logo1.png)

A simple and useful `node.js` tool written in C++/JS using Node-API for decode/encode your FIT files.

## Project goals

The aim of this project is to have an up-to-date and fully customizable parser. Taking the advantage of [Node-API](https://duckduckgo.com), this tool interact directly with the C++ structures of the [Garmin&copy; FIT SDK](https://developer.garmin.com/fit/overview/).

## Table of Contents

1. [Prerequisites](#1-prerequisites)
2. [Installation](#2-installation)
3. [Development](#3-development)
4. [Deployment](#4-deployment)
5. [Run](#5-run)
6. [ToDo](#6-todo)

---

## 1) Prerequisites

To compile the addon you need a toolchain that compile C and C++ code into a binary.

![a](res/icons8-nodejs-16.png) **node**

The NodeJS ecosystem is mandatory and can be installed downloading the binaries for your architecture, [here](https://nodejs.org/en/).

![a](res/icons8-linux-16.png) **Linux**

For Linux developers, a proper C/C++ compiler toolchain, like [GCC](https://gcc.gnu.org).

![a](res/icons8-apple-logo-16.png) **macOS**

For macOS developers, install _XCode Command Line Tools_ which will install clang, clang++, and make.
Type into the terminal:

```
xcode-select --install
```

![a](res/icons8-windows8-16.png) **Windows**

For Windows developers there is nothing to do. The build tools system is now shipped with Node.js.

![a](res/icons8-hexagon-16.png) **node-gyp**

After developing process, to correctly deploying the addon, you need `node-gyp` build system installed.
You can find all the information needed, [here](https://github.com/nodejs/node-gyp).

---

## 2) Installation

To install the others development packages, simply type into the terminal:

```
npm install
```

---

## 3) Development

The core of the addon is inside the ![a](res/icons8-directory-16.png) **src** folder and it is structured like below:

- ![a](res/icons8-directory-16.png) **configuration** - utility functions and defines.
- ![a](res/icons8-directory-16.png) **decode** - C++ class to decode FIT file.
- ![a](res/icons8-directory-16.png) **encode** - C++ class to encode FIT file.
- ![a](res/icons8-directory-16.png) **fit** - source code of the FIT&copy; SDK<sup>1,2</sup>.
- ![a](res/icons8-directory-16.png) **nlohmann** a wonderful C++ class for handle JSON objects. More information at [nlohmann/json](https://github.com/nlohmann/json).
- ![a](res/icons8-directory-16.png) **worker** - the async N-API C++ class for schedule the parsing process to the background avoiding Node's main loop.
- ![a](res/icons8-file-16.png) **fit_parser.cpp/fit_parser.hpp** - N-API wrapper class that expose all the addon functionalities.
- ![a](res/icons8-file-16.png) **main.cpp** - The entry point of the module.

FIT&copy; SDK<sup>1</sup>: The version used is _21.67_. To update to the latest version, simply download [SDK](https://developer.garmin.com/fit/download/) from Garmin&copy; website, uncompress it, and replace all the **source** files inside folder ![a](res/icons8-directory-16.png) **fit** with the _source_ files present into folder ![a](res/icons8-directory-16.png) **cpp** just downloaded.

FIT&copy; SDK<sup>2</sup>: You're free(and encouraged) to use also custom FIT class. Only two things are mandatory to be able to use custom messages:

- ![a](res/icons8-info-16.png) Custom files must be included in the ![a](res/icons8-directory-16.png) **fit** folder
- ![a](res/icons8-info-16.png) They must be created with the officia tool ![a](res/icons8-wrench-16.png) **FitGen.exe** shipped with the SDK.

---

## 4) Deployment

After the installation step you can build the addon module with the following command:

```
npm run build
```

The command will produce the binary file inside the folder ![a](res/icons8-directory-16.png) <b>binary/{platform}/FITParser.node</b>.

### Other commands

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

### Pre/Post Scritps

Content of the ![a](res/icons8-directory-16.png) **scripts** folder:

- `post.js` - for moving the compiled module in the convenient folder ![a](res/icons8-directory-16.png) **binary**.

## 5) Run

Include the module

```js
const fitModule = require("FITParser.node");
```

---

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

---

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

id<sup>1</sup>: All message _ids_ can be retrieved from property `defines` of `fitModule` object like below:

```js
fitModule.defines.FILE_ID; // = 0
fitModule.defines.FILE_CREATOR; // = 1
...
```

The complete list is visible in the header ![a](res/icons8-file-16.png) `fit_profile.hpp`.

---

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

In folder ![a](res/icons8-directory-16.png) **example** there are different types of FIT&copy; files you can choose to test the module.

## 6) Under development

![a](res/icons8-error-16.png) <span style="font-weight:bold; color: #FCC419;">Encode functionalities are now in development, are can not work as expected.</span>

### ![a](res/icons8-download-16-2.png) Encode object

```js
fitModule.encodeFile("filepath", fitObj, [options], (err, result) => ...)
```

Params:

| Name     |           Mandatory           | Type          | Descriptions                                       |
| -------- | :---------------------------: | ------------- | -------------------------------------------------- |
| filepath | ![a](res/icons8-done-16.png)  | _Buffer_      | representing the path where the file will be saved |
| fitObj   | ![a](res/icons8-done-16.png)  | _JSON object_ | JSON object represent the .FIT file to be written  |
| options  | ![a](res/icons8-close-16.png) | _JSON array_  | see [encode options](#encode-options)              |
| callback | ![a](res/icons8-done-16.png)  | _Function_    | the callback function                              |

Callback params:

| Name | Type          | Descriptions                                                                                      |
| ---- | ------------- | ------------------------------------------------------------------------------------------------- |
| err  | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_                       |
| info | _JSON array_  | a JSON array containing warnings<sup>**1**</sup> object(JSON object composed by _message_/_code_) |

Warnings<sup>**1**</sup>: array not empty, means there is something in `fitObj` that is not ok but the .fit file will still be produced.

---

### ![a](res/icons8-download-16-2.png) Encode buffer

```js
fitModule.encodeBuffer("filepath", buffer, [options], (err, result) => ...)
```

Params:

| Name     |           Mandatory           | Type         | Descriptions                                       |
| -------- | :---------------------------: | ------------ | -------------------------------------------------- |
| filepath | ![a](res/icons8-done-16.png)  | _Buffer_     | representing the path where the file will be saved |
| buffer   | ![a](res/icons8-done-16.png)  | _Buffer_     | the\*Buffer object of the FIT file to encode       |
| options  | ![a](res/icons8-close-16.png) | _JSON array_ | see [encode options](#encode-options)              |
| callback | ![a](res/icons8-done-16.png)  | _Function_   | the callback function                              |

Callback params:

| Name | Type          | Descriptions                                                                                      |
| ---- | ------------- | ------------------------------------------------------------------------------------------------- |
| err  | _JSON string_ | the JSON string representing error. Is composed by a _message_ and a _code_                       |
| info | _JSON array_  | a JSON array containing warnings<sup>**1**</sup> object(JSON object composed by _message_/_code_) |

Warnings<sup>**1**</sup>: array not empty, means there is something in `fitObj` that is not ok but the .fit file will still be produced.

---

### ![a](res/icons8-download-16-2.png) Encode options

All the available decode options are listed below:

| Option name | Type               | Default     | Description                                                                                |
| ----------- | ------------------ | ----------- | ------------------------------------------------------------------------------------------ |
| exclude     | _Array of numbers_ | _undefined_ | An array of message's id<sup>1</sup> representing the messages to be skipped from encoding |

id<sup>1</sup>: All message _ids_ can be retrieved from property `defines` of `fitModule` object like below:

```js
fitModule.defines.FILE_ID; // = 0
fitModule.defines.FILE_CREATOR; // = 1
...
```

The complete list is visible in the header ![a](res/icons8-file-16.png) `fit_profile.hpp`.

---

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

---

## Attributions

All logo/icons of the project are provided by [Icon8](https://icons8.com).
