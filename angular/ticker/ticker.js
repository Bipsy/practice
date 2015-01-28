var ticker = angular.module("ticker", []);

ticker.controller("tickerCtrl", function($scope) {
	$scope.name = "Peter";
	$scope.stuff = [
		{
			'type': 'like',
		 	'text': 'Snowboarding'},
		{
			'type': 'dislike',
			'text': 'Nazis'
		}
	]
	
});

ticker.filter('liker', function() {
	return function(input) {
		if (input.type === 'like') {
			return input.text;
		}
	};
})

