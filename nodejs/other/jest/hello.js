module.exports = class Hello {
    constructor(msg) {
        this.msg = msg;
    }
    // hello
    hello() {
        return "hello " + this.msg;
    }
}