const N = 1000000

function runSimulation(families) {
  let girls = 0
  let boys = 0

  for (let i = 0; i < families; i++) {
    let hasHadGirl = false
    while (!hasHadGirl) {
      if (Math.random() < .5) {
        girls++
        hasHadGirl = true
      } else {
        boys++
      }
    }
  }

  console.log({ girls, boys })
}

runSimulation(N)