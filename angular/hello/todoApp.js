var myapp = angular.module('todoApp', []);

myapp.controller('Ctrl', [function() {
	this.remaining = 1;
	this.total = 2;
	this.newItem = "";
	this.completedItems = [];
	this.items = [
		{text:"Write Paper", done:false},		
		{text:"Brush Teeth", done:false}];
	this.addItem = function() {
		this.items.push({text:this.newItem, done:false});
		this.newItem = "";
	};
	this.checkItem = function() {
		if (this.newItem === "") {
			return false;
		} else {
			return true;
		}
	};
	this.removeItem = function(item) {
		var index = this.items.indexOf(item);
		if (index != -1) {
			item.done = true;
			this.completedItems.push(item);
			this.items.splice(index, 1);
		}
	};
}]);