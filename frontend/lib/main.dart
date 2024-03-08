import "package:flutter/material.dart";
import "package:frontend/src/pages/home/index.dart";


void main(){
  runApp(const MyApp());
}


class MyApp extends StatelessWidget {
  const MyApp({ super.key });

  @override 
  Widget build(BuildContext context){
    return const MaterialApp(
      title : "Remote LED",
      debugShowCheckedModeBanner: false,
      home : HomeView()
    );
  }
}