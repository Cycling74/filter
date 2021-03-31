{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 2,
			"revision" : 0,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 23.0, 48.0, 507.0, 718.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Lato",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 2,
		"toptoolbarpinned" : 2,
		"righttoolbarpinned" : 2,
		"bottomtoolbarpinned" : 2,
		"toolbars_unpinned_last_save" : 15,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"showrootpatcherontab" : 0,
		"showontab" : 0,
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 2,
							"revision" : 0,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 23.0, 74.0, 507.0, 692.0 ],
						"bglocked" : 0,
						"openinpresentation" : 1,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"enablehscroll" : 0,
									"enablevscroll" : 0,
									"id" : "obj-47",
									"lockeddragscroll" : 0,
									"maxclass" : "bpatcher",
									"name" : "visualizer.maxpat",
									"numinlets" : 2,
									"numoutlets" : 1,
									"offset" : [ 0.0, 0.0 ],
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 228.385948937591536, 432.0, 222.828607000000005 ],
									"presentation" : 1,
									"presentation_rect" : [ 33.0, 150.0, 432.0, 222.828607000000005 ],
									"viewvisibility" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 409.0, 137.0, 70.0, 22.0 ],
									"text" : "loadmess 0"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 2,
									"fontname" : "Lato",
									"id" : "obj-17",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 65.0, 644.0, 247.0, 21.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 50.0, 483.0, 46.0, 21.0 ],
									"text" : "Note:"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 2,
									"fontname" : "Lato",
									"id" : "obj-38",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 629.0, 247.0, 35.0 ],
									"presentation" : 1,
									"presentation_linecount" : 2,
									"presentation_rect" : [ 79.0, 505.0, 366.0, 35.0 ],
									"text" : "All filters displayed are 8th-order lowpass filters with a frequency of 2000 Hz."
								}

							}
, 							{
								"box" : 								{
									"fontface" : 2,
									"fontname" : "Lato",
									"id" : "obj-33",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 559.0, 315.0, 64.0 ],
									"presentation" : 1,
									"presentation_linecount" : 4,
									"presentation_rect" : [ 79.0, 542.0, 366.0, 64.0 ],
									"text" : "Not all filter types define their cutoff frequency using the same criteria. For example, Chebyshev2 filters define the frequency parameter to mean the beginning of the stopband rather than the end of the passband."
								}

							}
, 							{
								"box" : 								{
									"fontface" : 2,
									"fontname" : "Lato",
									"id" : "obj-26",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 674.0, 301.0, 64.0 ],
									"presentation" : 1,
									"presentation_linecount" : 3,
									"presentation_rect" : [ 79.0, 608.0, 366.0, 50.0 ],
									"text" : "In the phase plots, the blotch of color at the far right end is not the phase response of the actual filter but round-off noise. (This visualization uses an unwindowed impulse response.)"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Lato",
									"id" : "obj-15",
									"linecount" : 8,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 504.0, 97.0, 122.0 ],
									"presentation" : 1,
									"presentation_linecount" : 2,
									"presentation_rect" : [ 50.0, 385.828607000000034, 399.0, 35.0 ],
									"text" : "The Bessel filter has the slowest rolloff but maximally-linear phase response. It is often used in crossover applications."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "message",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 470.0, 50.0, 22.0 ],
									"text" : "set $1"
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Lato",
									"id" : "obj-1",
									"items" : [ "Bessel", ",", "Butterworth", ",", "Legendre", ",", "Chebyshev-1", ",", "Chebyshev-2", ",", "Elliptic" ],
									"maxclass" : "umenu",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "int", "", "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 50.0, 201.385948937591536, 149.0, 23.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 33.0, 124.0, 117.0, 23.0 ]
								}

							}
, 							{
								"box" : 								{
									"bgmode" : 0,
									"border" : 0,
									"clickthrough" : 0,
									"embed" : 1,
									"enablehscroll" : 0,
									"enablevscroll" : 0,
									"id" : "obj-11",
									"lockeddragscroll" : 0,
									"maxclass" : "bpatcher",
									"name" : "visualizer-tabs.maxpat",
									"numinlets" : 0,
									"numoutlets" : 1,
									"offset" : [ 0.0, 0.0 ],
									"outlettype" : [ "" ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 8,
											"minor" : 2,
											"revision" : 0,
											"architecture" : "x64",
											"modernui" : 1
										}
,
										"classnamespace" : "box",
										"rect" : [ 791.0, 340.0, 274.0, 480.0 ],
										"bglocked" : 0,
										"openinpresentation" : 1,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 1,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 1,
										"objectsnaponopen" : 1,
										"statusbarvisible" : 2,
										"toolbarvisible" : 1,
										"lefttoolbarpinned" : 0,
										"toptoolbarpinned" : 0,
										"righttoolbarpinned" : 0,
										"bottomtoolbarpinned" : 0,
										"toolbars_unpinned_last_save" : 0,
										"tallnewobj" : 0,
										"boxanimatetime" : 200,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"description" : "",
										"digest" : "",
										"tags" : "",
										"style" : "",
										"subpatcher_template" : "",
										"assistshowspatchername" : 0,
										"boxes" : [ 											{
												"box" : 												{
													"fontname" : "Lato",
													"id" : "obj-7",
													"maxclass" : "textbutton",
													"numinlets" : 1,
													"numoutlets" : 3,
													"outlettype" : [ "", "", "int" ],
													"parameter_enable" : 0,
													"patching_rect" : [ 117.0, 14.0, 99.0, 24.0 ],
													"presentation" : 1,
													"presentation_rect" : [ 100.0, 0.0, 99.0, 24.0 ],
													"text" : "Phase response",
													"texton" : "Phase response",
													"textoncolor" : [ 0.980392156862745, 0.980392156862745, 0.980392156862745, 1.0 ]
												}

											}
, 											{
												"box" : 												{
													"fontname" : "Lato",
													"id" : "obj-5",
													"maxclass" : "textbutton",
													"numinlets" : 1,
													"numoutlets" : 3,
													"outlettype" : [ "", "", "int" ],
													"parameter_enable" : 0,
													"patching_rect" : [ 12.0, 14.0, 99.0, 24.0 ],
													"presentation" : 1,
													"presentation_rect" : [ 0.0, 0.0, 99.0, 24.0 ],
													"text" : "Freq response",
													"texton" : "Freq response",
													"textoncolor" : [ 0.980392156862745, 0.980392156862745, 0.980392156862745, 1.0 ]
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-3",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 117.0, 49.0, 75.0, 22.0 ],
													"text" : "offset -432 0"
												}

											}
, 											{
												"box" : 												{
													"id" : "obj-2",
													"maxclass" : "message",
													"numinlets" : 2,
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 12.0, 49.0, 58.0, 22.0 ],
													"text" : "offset 0 0"
												}

											}
, 											{
												"box" : 												{
													"comment" : "",
													"id" : "obj-9",
													"index" : 1,
													"maxclass" : "outlet",
													"numinlets" : 1,
													"numoutlets" : 0,
													"patching_rect" : [ 12.0, 96.0, 30.0, 30.0 ]
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"source" : [ "obj-2", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-9", 0 ],
													"source" : [ "obj-3", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-2", 0 ],
													"source" : [ "obj-5", 0 ]
												}

											}
, 											{
												"patchline" : 												{
													"destination" : [ "obj-3", 0 ],
													"source" : [ "obj-7", 0 ]
												}

											}
 ]
									}
,
									"patching_rect" : [ 280.0, 201.385948937591536, 202.0, 25.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 266.0, 123.0, 202.0, 25.0 ],
									"viewvisibility" : 1
								}

							}
, 							{
								"box" : 								{
									"fontface" : 3,
									"fontname" : "Lato",
									"id" : "obj-8",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 55.0, 166.0, 338.0, 21.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 17.0, 81.0, 396.0, 21.0 ],
									"text" : "A collection of IIR filters available as MSP and Jitter objects."
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Lato Heavy",
									"fontsize" : 52.0,
									"id" : "obj-4",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 62.0, 100.0, 249.0, 69.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 17.0, 10.0, 249.0, 69.0 ],
									"text" : "Filter"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 1 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-15", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 5.0, 10.0, 109.0, 23.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p \"Filter Overview\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 2,
							"revision" : 0,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "box",
						"rect" : [ 0.0, 26.0, 507.0, 692.0 ],
						"bglocked" : 0,
						"openinpresentation" : 1,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Lato",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 2,
						"toptoolbarpinned" : 2,
						"righttoolbarpinned" : 2,
						"bottomtoolbarpinned" : 2,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-41",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 322.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 329.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.elliptic",
									"texton" : "filter.jit.elliptic",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-42",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 290.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 297.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.chebyshev2",
									"texton" : "filter.jit.chebyshev2",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-43",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 258.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 265.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.chebyshev1",
									"texton" : "filter.jit.chebyshev1",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-44",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 226.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 233.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.legendre",
									"texton" : "filter.jit.legendre",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-45",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 194.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 201.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.butterworth",
									"texton" : "filter.jit.butterworth",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 328.5, 162.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 250.5, 169.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.jit.bessel",
									"texton" : "filter.jit.bessel",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-40",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 386.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 393.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.dcblock~",
									"texton" : "filter.dcblock~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-39",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 354.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 361.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.one~",
									"texton" : "filter.one~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-38",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 322.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 329.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.elliptic~",
									"texton" : "filter.elliptic~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-37",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 290.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 297.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.chebyshev2~",
									"texton" : "filter.chebyshev2~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-36",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 258.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 265.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.chebyshev1~",
									"texton" : "filter.chebyshev1~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-35",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 226.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 233.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.legendre~",
									"texton" : "filter.legendre~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-34",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 194.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 201.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.butterworth~",
									"texton" : "filter.butterworth~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 94.0, 583.0, 52.0, 23.0 ],
									"text" : "pcontrol"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 94.0, 548.0, 78.0, 23.0 ],
									"text" : "prepend help"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "textbutton",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "", "", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 178.5, 162.0, 144.0, 27.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 100.5, 169.0, 144.0, 27.0 ],
									"rounded" : 5.0,
									"style" : "igk",
									"text" : "filter.bessel~",
									"texton" : "filter.bessel~",
									"textoncolor" : [ 0.929411764705882, 0.956862745098039, 0.964705882352941, 1.0 ],
									"textovercolor" : [ 0.997536, 0.883331, 0.611546, 1.0 ],
									"usetextovercolor" : 1
								}

							}
, 							{
								"box" : 								{
									"fontface" : 3,
									"fontname" : "Lato",
									"id" : "obj-25",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 17.0, 81.0, 76.0, 21.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 17.0, 81.0, 76.0, 21.0 ],
									"text" : "Object listing"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 1,
									"fontname" : "Lato Heavy",
									"fontsize" : 52.0,
									"id" : "obj-24",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 17.0, 10.0, 249.0, 69.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 17.0, 10.0, 249.0, 69.0 ],
									"text" : "Filter"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 3,
									"fontname" : "Lato",
									"id" : "obj-23",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 383.0, 134.0, 35.0, 21.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 305.0, 141.0, 35.0, 21.0 ],
									"text" : "Jitter"
								}

							}
, 							{
								"box" : 								{
									"fontface" : 3,
									"fontname" : "Lato",
									"id" : "obj-22",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 234.5, 134.0, 32.0, 21.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 156.5, 141.0, 32.0, 21.0 ],
									"text" : "MSP"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-26", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-31", 0 ],
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-34", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-35", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-36", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-37", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-38", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-39", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-40", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-41", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-42", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-43", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-44", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-45", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-30", 0 ],
									"source" : [ "obj-46", 1 ]
								}

							}
 ],
						"styles" : [ 							{
								"name" : "Audiomix",
								"default" : 								{
									"bgfillcolor" : 									{
										"type" : "gradient",
										"color1" : [ 0.376471, 0.384314, 0.4, 1.0 ],
										"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
										"color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
										"angle" : 270.0,
										"proportion" : 0.39
									}

								}
,
								"parentstyle" : "",
								"multi" : 0
							}
, 							{
								"name" : "Max 12 Regular",
								"parentstyle" : "",
								"multi" : 0
							}
, 							{
								"name" : "igk",
								"default" : 								{
									"color" : [ 0.847058823529412, 0.882352941176471, 0.890196078431372, 1.0 ],
									"selectioncolor" : [ 0.849573, 1.0, 0.926902, 1.0 ]
								}
,
								"parentstyle" : "",
								"multi" : 0
							}
, 							{
								"name" : "tap",
								"default" : 								{
									"fontname" : [ "Lato Light" ]
								}
,
								"parentstyle" : "",
								"multi" : 0
							}
 ]
					}
,
					"patching_rect" : [ 140.0, 10.0, 96.0, 37.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"fontname" : "Lato",
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p \"Object listing\""
				}

			}
 ],
		"lines" : [  ],
		"dependency_cache" : [ 			{
				"name" : "visualizer.maxpat",
				"bootpath" : "~/Desktop",
				"patcherrelativepath" : "../../../../../Desktop",
				"type" : "JSON",
				"implicit" : 1
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "Audiomix",
				"default" : 				{
					"bgfillcolor" : 					{
						"type" : "gradient",
						"color1" : [ 0.376471, 0.384314, 0.4, 1.0 ],
						"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"angle" : 270.0,
						"proportion" : 0.39
					}

				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "Max 12 Regular",
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "tap",
				"default" : 				{
					"fontname" : [ "Lato Light" ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
