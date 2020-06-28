// sum.test.js
const Hello = require('./hello');
const hello = new Hello("jest");

test('adds 1 + 2 to equal 3', () => {
  expect(hello.hello()).toBe("hello jest");
});