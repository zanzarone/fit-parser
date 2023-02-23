const path = require("path");
const fs = require("fs");
const clc = require("cli-color");
const fitModule = require(path.join(process.cwd(), "binary", process.platform, "FITParser.node"));
const titleMsg = clc.xterm(202).bgXterm(236).bold;
const errorsMsg = clc.xterm(15).bgXterm(160).bold;
const warningMsg = clc.xterm(0).bgXterm(226).bold;
const debugMsg = clc.xterm(14);
const successMsg = clc.xterm(47);
const prompt = require("prompt-sync")({ sigint: true });

const TEST_FILE1 = "./examples/Settings.fit";
const TEST_FILE2 = "./examples/Activity.fit";
const TEST_FILE3 = "./examples/Activity.json";

function askUser() {
  let select = prompt("Choose an option: ");
  while (isNaN(select) || Number(select) < 0 || Number(select) > 4) {
    select = prompt("Choose a valid option[0-3]: ");
  }
  return Number(select);
}

function showMenu() {
  console.log(titleMsg("N-API FIT MODULE V." + fitModule.version));
  console.log(debugMsg("\t ====== MENU ======="));
  console.log(debugMsg("1)\t Decode file example"));
  console.log(debugMsg("2)\t Decode buffer await example"));
  console.log(debugMsg("3)\t Encode buffer example"));
  console.log(debugMsg("4)\t Encode file await example"));
  console.log(debugMsg("0)\t Quit"));
  console.log();
  let select = askUser();
  switch (select) {
    case 0:
      console.log(successMsg("Bye."));
      break;
    case 1:
      opt1();
      break;
    case 2:
      opt2();
      break;
    case 3:
      opt3();
      break;
    case 4:
      opt4();
      break;
  }
}

function opt1Callback(err, fitString) {
  if (err) {
    console.log(errorsMsg(`Errore decoding ${TEST_FILE1}: ${err.message}(${err.code})`));
  } else {
    try {
      const FIT = JSON.parse(fitString);
      console.log(successMsg(`Successfully decoded ${TEST_FILE1}:`));
      console.dir(FIT, { depth: null });
    } catch (error) {
      console.log(error);
    }
  }
  showMenu();
}

function opt1() {
  console.log("Decoding file", TEST_FILE1);
  fitModule.decodeFile(TEST_FILE1, opt1Callback, { rawValues: false });
}

async function opt2() {
  console.log("Decoding file - (async/await)", TEST_FILE2);
  try {
    const fitString = await fitModule.decodeFileAsync(TEST_FILE2, { rawValues: true });
    const FIT = JSON.parse(fitString);
    console.log(successMsg(`Successfully decoded ${TEST_FILE2}:`));
    console.dir(FIT, { depth: null });
  } catch (error) {
    console.log(error);
  } finally {
    showMenu();
  }
}

function opt3() {}

async function opt4() {
  console.log("Encoding file", TEST_FILE3);
  try {
    const data = fs.readFileSync(TEST_FILE3, "utf-8");
    // console.log("1", data);
    const lll = await fitModule.encodeJSONToFileAsync("./output/pippo.fit", data);
    // console.log("1", lll);
    const reopen = fs.readFileSync("./output/pippo.fit", { encoding: "binary", flag: "r" });
    // console.log("1", reopen);
    const result = await fitModule.decodeBufferAsync(reopen);
    // console.log("1");
    console.dir(result, { depth: null });
    console.log("1");
  } catch (error) {
    console.log("aaaa", error);
  }
}

showMenu();
