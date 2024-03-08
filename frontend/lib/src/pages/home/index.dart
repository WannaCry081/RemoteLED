import "dart:convert";
import "package:flutter/material.dart";
import "package:http/http.dart" as http;


class HomeView extends StatefulWidget {
  const HomeView({ super.key });

  @override
  State<HomeView> createState() => _HomeViewState();
}

class _HomeViewState extends State<HomeView> {

  String url = "https://192.168.100.24:8000/api/v1/light/1/";

  bool status = false;

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

  Future<bool> fetchData() async {
    final response = await http.get(Uri.parse(url));
    final data = json.decode(response.body)["led"] as bool;
    return data;
  }

  Future<void> updateData(bool data) async {
    await http.patch(
      Uri.parse(url),
      body : json.encode({ "led" : data })
    );
  }

}