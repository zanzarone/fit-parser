const fs = require("fs");
const clc = require("cli-color");
const path = require("path");
const fitModule = require(path.join(
  process.cwd(),
  "binary",
  `FITParser-${process.platform}.node`
));
const titleMsg = clc.xterm(121).bgXterm(236).bold;
// const errorsMsg = clc.xterm(15).bgXterm(160).bold;
const errorsMsg = clc.xterm(160).bold;
const warningMsg = clc.xterm(0).bgXterm(226).bold;
const debugMsg = clc.xterm(14);
const successMsg = clc.xterm(47);
const prompt = require("prompt-sync")({ sigint: true });

const printJson = (jsonString) => {
  try {
    const parsed = JSON.parse(jsonString);
    console.dir(parsed, { depth: null });
  } catch (exc) {
    console.log(errorsMsg(`Errore decoding ${exc.message}\n${exc.code}`));
  }
};

function askUser() {
  let select = prompt("Choose an option: ");
  while (isNaN(select) || Number(select) < 0 || Number(select) > 5) {
    select = prompt("Choose a valid option[0-5]: ");
  }
  return Number(select);
}

const options = {
  force: true,
  rawValues: true,
};

function decodeFileExample(filePath) {
  fitModule.decodeFile(
    //@ PATH
    filePath,
    //@ CALLBACK
    (err, fitString) => {
      if (err) {
        console.log(
          errorsMsg(`Errore decoding ${filePath}: ${err.message}(${err.code})`)
        );
        return;
      }
      try {
        const outputFilePath = path.join(
          __dirname,
          "..",
          "examples",
          "output",
          "Activity.json"
        );
        console.log(successMsg(`Successfully decoded!`));
        fs.writeFileSync(outputFilePath, fitString);
      } catch (error) {
        console.log(
          errorsMsg(`Errore decoding ${filePath}: ${err.message}\n${err.stack}`)
        );
      }
    },
    //@ OPTIONS
    options
  );
}

async function decodeFileAsyncExample(filePath) {
  try {
    const fitString = await fitModule.decodeFileAsync(filePath, options);
    const outputFilePath = path.join(
      __dirname,
      "..",
      "examples",
      "output",
      "Activity.json"
    );
    console.log(successMsg(`Successfully decoded`));
    fs.writeFileSync(outputFilePath, fitString);
  } catch (error) {
    console.log(errorsMsg(`Errore decoding: ${err.message}\n${err.stack}`));
  }
}

function encodeFileFromBufferExample(filePath, outputFilePath) {
  console.log(filePath);
  let buffer;
  try {
    buffer = fs.readFileSync(filePath);
  } catch (error) {
    console.log(errorsMsg(`Errore encoding at ${filePath}: ${err.message}(${err.code})`));
    return;
  }
  console.log(typeof buffer);
  try {
    fitModule.encodeJsonBufferToFile(
      //@ FILEPATH
      outputFilePath,
      //@ BUFFER
      buffer,
      //@ CALLBACK
      (err) => {
        if (err) {
          console.log(
            errorsMsg(`Errore encoding at ${filePath}: ${err.message}(${err.code})`)
          );
          return;
        }
        console.log(successMsg(`Successfully encoded at ${filePath}!`));
      }
    );
  } catch (error) {
    console.log(errorsMsg(`Errore encoding at ${filePath}: ${error.message}`));
  }
}

function encodeFileFromJsonExample(filePath, outputFilePath) {
  console.log("Encoding file");
  let jsonString;
  try {
    jsonString = fs.readFileSync(filePath, "utf-8");
  } catch (error) {
    console.log(errorsMsg(`Errore encoding at ${filePath}: ${err.message}(${err.code})`));
    return;
  }

  try {
    fitModule.encodeJsonToFile(
      //@ FILEPATH
      outputFilePath,
      //@ BUFFER
      jsonString,
      //@ CALLBACK
      (err) => {
        if (err) {
          console.log(
            errorsMsg(`Errore encoding at ${filePath}: ${err.message}(${err.code})`)
          );
          return;
        }
        console.log(successMsg(`Successfully encoded at ${filePath}!`));
      }
    );
  } catch (error) {
    console.log(errorsMsg(`Errore encoding at ${filePath}: ${error.message}`));
  }
}

function showMenu() {
  console.log();
  console.log(titleMsg("    N-API FIT MODULE V." + fitModule.version + "    "));
  console.log();
  console.log(debugMsg("1)\t Decode file example"));
  console.log(debugMsg("2)\t Awaitable decode file example"));
  console.log(debugMsg("3)\t Encode file from buffer"));
  console.log(debugMsg("4)\t Encode file from json string"));
  console.log(debugMsg("0)\t Quit"));
  console.log();
  let select = askUser();
  switch (select) {
    case 0:
      return console.log(successMsg("Bye."));
    case 1: {
      const filePath = path.join(__dirname, "..", "examples", "Activity.fit");
      return decodeFileExample(filePath);
    }
    case 2: {
      const filePath = path.join(__dirname, "..", "examples", "Activity.fit");
      return decodeFileAsyncExample(filePath);
    }
    case 3: {
      const filePath = path.join(__dirname, "..", "examples", "Activity.json");
      const outputFilePath = path.join(
        __dirname,
        "..",
        "examples",
        "output",
        `ActivityFromJsonBuffer-${new Date().toISOString()}.fit`
      );
      return encodeFileFromBufferExample(filePath, outputFilePath);
    }
    case 4: {
      const filePath = path.join(__dirname, "..", "examples", "Activity.json");
      const outputFilePath = path.join(
        __dirname,
        "..",
        "examples",
        "output",
        `ActivityFromJson-${new Date().toISOString()}.fit`
      );
      return encodeFileFromJsonExample(filePath, outputFilePath);
    }
    case 5:
      opt5();
      break;
  }
}

async function start() {
  const outFolder = path.join(__dirname, "..", "examples", "output");
  try {
    if (!fs.existsSync(outFolder)) {
      fs.mkdirSync(outFolder);
      console.log(debugMsg(`Output folder created at ${outFolder}`));
    }
  } catch (err) {
    console.log(errorsMsg(`Error: ${err.message}(${err.code})`));
  }
  showMenu();
}

start();
