<p align="center">Layout detection framework for DirectX11 applications. Serves currently as a concept document.</p>

##

<br>

## Concepts
```json
// All scenes
scenes: [
	// Single scene object
	{
		name: 'foundry',				// Name of the scene
		screenshot: 'img/foundry.jpg',	// Screenshot to base on
		conditions: [				// Conditions to meet
			{						// Single condition object
				function: 'ocr',			// Function to eval to
				match: 'FOUNDRY',			// Match for the condition to return true
				params: [450, 30, 550, 50],	// Parameters for the function
			},
			{
				function: 'color',
				match: 0xFFFFFF,
				params: [450, 20]
			}, 
			...
		],

		// Children objects
		objects: [
			// Single children object
			{
				name: 'item'				// Name of the object
				area: [50, 50, 300, 100],	// Template area to match in the scenes screenshot
				conditions: [],	// Conditions to meet

				states: [		// States the item has
					{			// Single state	
						name: 'building',	// item.building
						conditions: [		// Conditions to meet
							{
								function: 'ocr',
								match: 'BUILD',
								params: [280, 80, 300, 100],
							},
							...
						],
					}
				],

				instances: [	// Actual instances of the item
					[50, 50],	// Single instance
					[350, 50],
					[50, 150],
					[350, 150],
					...
				],
			},
			...
		],
	},
	...
],
```

<br>

## License
[MIT](/LICENSE.md)