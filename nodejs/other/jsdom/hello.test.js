const jsdom = require("jsdom");
const { JSDOM } = jsdom;

test('use jsdom', () => {
    const dom = new JSDOM(`<!DOCTYPE html><p>Hello world</p>`);
    expect(dom.window.document.querySelector("p").textContent).toBe("Hello world");
});