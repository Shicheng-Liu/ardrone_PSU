var arDrone = require('ar-drone');
var client  = arDrone.createClient();
client.takeoff();

client
  .after(5000, function() {
    this.front(0.1);
  })
  .after(5000, function() {
    this.back(0.07);
  })
  .after(5000, function() {
    this.clockwise(0.5)
  })
  .after(5000, function() {
    this.stop();
    this.land();
  })

