import "dart:convert";
import "package:flutter/material.dart";
import "package:http/http.dart";


class HomeView extends StatefulWidget {
  const HomeView({ super.key });

  @override
  State<HomeView> createState() => _HomeViewState();
}

class _HomeViewState extends State<HomeView> {
  @override
  Widget build(BuildContext context){
    return Scaffold(
      backgroundColor: Colors.deepPurple[100],
      appBar : AppBar(
        backgroundColor: Colors.deepPurple[400],
        title: const Text("LED Controller"),
      ),
      body : Center(
        child : Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children : [
            Text("LED Status: "),
            const SizedBox(height : 10),
            ElevatedButton(
              child : const Text("LED"),
              onPressed: (){},
            )
          ]
        )
      )
    );
  }
}