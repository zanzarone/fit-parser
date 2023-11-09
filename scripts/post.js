const path = require("path");
const fs = require("fs");
// console.log(pjson.version);
const platform = process.platform;
// var child_process = require('child_process');
console.log("=======================");
console.log("=========  POST BUILD ===========");
console.log("=======================");
console.log(`=========  current platform:${platform}  ===========`);
console.log("=======================");

function postBuild() {
  const releaseFolder = path.join(".", "build", "Release");
  const files = fs.readdirSync(releaseFolder).filter((fn) => fn.startsWith("FITParser.node"));
  if (!files || files.length <= 0) {
    console.log("=========  Error: no release candidate found ===========");
    return;
  }
  const releaseFile = files.shift();
  let oldPath = path.resolve(path.join(releaseFolder, path.basename(releaseFile)));
  let newPath = path.resolve(path.join(".", "binary"));
  if (!fs.existsSync(newPath)) {
    fs.mkdirSync(newPath, { recursive: true });
  }
  newPath = path.resolve(path.join(newPath, `FITParser-${platform}.node`));
  // newPath = path.resolve(path.join(newPath, path.basename(releaseFile)));
  console.log(oldPath, newPath);

  fs.copyFile(oldPath, newPath, function (err) {
    if (err) {
      console.log(`=========  Error: ${err.message} ===========`);
      return;
    }
    console.log("=========  Binary successfully moved ===========");
  });
}

postBuild();
