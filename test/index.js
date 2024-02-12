const path = require("path");
const fs = require("fs");
const clc = require("cli-color");
const fitModule = require(path.join(
  process.cwd(),
  "binary",
  `FITParser-${process.platform}.node`
));
const titleMsg = clc.xterm(202).bgXterm(236).bold;
const errorsMsg = clc.xterm(15).bgXterm(160).bold;
const warningMsg = clc.xterm(0).bgXterm(226).bold;
const debugMsg = clc.xterm(14);
const successMsg = clc.xterm(47);
const prompt = require("prompt-sync")({ sigint: true });

const READ_FILE1 = "./examples/Activity.json";
const READ_FILE_FIT = "./private/PEDALI-simone-20240116134301";

function askUser() {
  let select = prompt("Choose an option: ");
  while (isNaN(select) || Number(select) < 0 || Number(select) > 5) {
    select = prompt("Choose a valid option[0-5]: ");
  }
  return Number(select);
}

function showMenu() {
  console.log(titleMsg("    N-API FIT MODULE V." + fitModule.version + "    "));
  console.log(debugMsg("\t ====== MENU ======="));
  console.log(debugMsg("1)\t Decode file example"));
  console.log(debugMsg("2)\t Decode buffer await example"));
  console.log(debugMsg("3)\t Encode buffer example"));
  console.log(debugMsg("4)\t Encode file await example"));
  console.log(debugMsg("5)\t Decode buffer await example and write to json"));
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
    case 5:
      opt5();
      break;
  }
}

async function start() {
  showMenu();
}

// async function start() {
//   console.log("Reading - (async/await)", READ_FILE_FIT);
//   try {
//     const fitString = await fitModule.decodeFileAsync(`${READ_FILE_FIT}.fit`, {
//       rawValues: true,
//     });
//     fs.writeFileSync(`./private/${new Date().toISOString()}.json`, fitString);
//   } catch (error) {
//     console.log(error);
//   } finally {
//     // showMenu();
//   }
// }

// async function start() {
//   console.log("Encoding file ");
//   try {
//     const data = fs.readFileSync(`./private/2024-02-12T13:35:55.213Z.json`, "utf-8");
//     // console.log("1", data);
//     const lll = await fitModule.encodeJSONToFileAsync(
//       "/Users/utente/Documents/NodeProjects/fit-parser/test/output/pippo2.fit",
//       data
//     );
//     console.log("errors:", lll);
//     // const reopen = fs.readFileSync("./output/pippo.fit", {
//     //   encoding: "binary",
//     //   flag: "r",
//     // });
//     // console.log("1", reopen);
//     // const result = await fitModule.decodeBufferAsync(reopen);
//     // console.log("1");
//     // console.dir(result, { depth: null });
//     // console.log("1");
//   } catch (error) {
//     console.log("aaaa", error);
//   }
// }

start();

// const TEST_FILE1 =
//   "/Users/samuele/Projects/Node/uploadServerJS/data/uploads/5edef77d490838ce/Settings.fit";
// const TEST_FILE1 = "/Users/samuele/Settings.fit";
// const TEST_FILE1 = "./private/srm pc8-20231119104138.fit";

// const TEST_FILE1 = "./private/2022_07_22_15_24_00.fit";
// const TEST_FILE2 = "./examples/Activity.fit";
// const TEST_FILE3 = "./examples/Activity.json";
// const TEST_FILE4 = "./examples/ActivityV20.fit";
// const READ_FILE1 =
//   "/Users/utente/Documents/NodeProjects/fit-parser/test/output/test.json";

// function opt1Callback(err, fitString) {
//   if (err) {
//     console.log(errorsMsg(`Errore decoding ${TEST_FILE1}: ${err.message}(${err.code})`));
//   } else {
//     try {
//       const FIT = JSON.parse(fitString);
//       console.log(successMsg(`Successfully decoded ${TEST_FILE1}:`));
//       console.dir(FIT, { depth: null });

//       let lat = null,
//         long = null;
//       try {
//         //? Parso il buffer con la mia bellissima libreria FitParser
//         //? leggo i record per cercare le coordinate
//         for (let i = FIT?.record?.msgs?.length - 1; i >= 0; i--) {
//           const record = FIT?.record?.msgs[i];
//           if (
//             record?.position_lat !== 0 &&
//             record?.position_long !== 0 &&
//             record?.position_lat !== fitModule.defines.FIT_SINT32_INVALID &&
//             record?.position_long !== fitModule.defines.FIT_SINT32_INVALID
//           ) {
//             lat = record.position_lat;
//             long = record.position_long;
//             break;
//           }
//         }
//       } catch (error) {
//         //? Non sono riuscito a parsare attivita'.
//         err("Error on activity parsing", JSON.stringify(error));
//         return;
//       }
//       if (lat && long) {
//         const lat_p = fitModule.semicirclesToDegrees(lat);
//         const long_p = fitModule.semicirclesToDegrees(long);
//         console.log(successMsg(`Successfully decoded ${lat} ${long}:`));
//         console.log(
//           successMsg(
//             `Successfully decoded ${lat_p} / ${fitModule.degreesToSemicircles(
//               lat_p
//             )} ${long_p}:`
//           )
//         );
//       }
//     } catch (error) {
//       console.log(error);
//     }
//   }
//   showMenu();
// }

// function opt1() {
//   console.log("Decoding file", soke);
//   fitModule.decodeFile(soke, opt1Callback, {
//     force: true,
//     rawValues: false,
//   });
// }

// async function opt2() {
// console.log("Decoding file - (async/await)", TEST_FILE2);
// try {
//   const fitString = await fitModule.decodeFileAsync(TEST_FILE2, {
//     rawValues: true,
//   });
//   const FIT = JSON.parse(fitString);
//   console.log(successMsg(`Successfully decoded ${TEST_FILE2}:`));
//   console.dir(FIT, { depth: null });
// } catch (error) {
//   console.log(error);
// } finally {
//   showMenu();
// }
// }

// function opt3() {}

// async function opt4() {
// console.log("Encoding file", READ_FILE1);
// try {
//   const data = fs.readFileSync(READ_FILE1, "utf-8");
//   // console.log("1", data);
//   const lll = await fitModule.encodeJSONToFileAsync(
//     "/Users/utente/Documents/NodeProjects/fit-parser/test/output/pippo.fit",
//     data
//   );
//   console.log("1", lll);
//   // const reopen = fs.readFileSync("./output/pippo.fit", {
//   //   encoding: "binary",
//   //   flag: "r",
//   // });
//   // console.log("1", reopen);
//   // const result = await fitModule.decodeBufferAsync(reopen);
//   // console.log("1");
//   // console.dir(result, { depth: null });
//   // console.log("1");
// } catch (error) {
//   console.log("aaaa", error);
// }
// }

// async function opt5() {
//   console.log("Decoding file - (async/await)", TEST_FILE4);
//   try {
//     const fitString = await fitModule.decodeFileAsync(TEST_FILE4, {
//       rawValues: true,
//     });
//     const FIT = JSON.parse(fitString);
//     console.log(successMsg(`Successfully decoded ${TEST_FILE4}:`));
//     // console.dir(FIT, { depth: null });
//     fs.writeFileSync(READ_FILE1, fitString);
//   } catch (error) {
//     console.log(error);
//   } finally {
//     showMenu();
//   }
// }

// showMenu();
