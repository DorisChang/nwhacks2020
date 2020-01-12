import React, { Component, useState} from 'react';
import {GoogleMap, withScriptjs, withGoogleMap, Marker, InfoWindow } from 'react-google-maps';

function Map() {
  const [selectedLocation, setSelectedLocation] = useState(null);

  return (
  <GoogleMap 
    defaultZoom = {12} 
    defaultCenter = {{lat: 49.282730, lng: -123.120735}} 
  >
  {<Marker key = "organizer's location" position= {{lat: 49.265236, lng: -123.249084}}
  // hard-coded organizer's location
  onClick={()=> {
    setSelectedLocation("organizer's location");
  }}
  />}

  {selectedLocation && (
    <InfoWindow
    position= {{lat: 49.265236, lng: -123.249084}}
    onCloseClick={()=>{
      setSelectedLocation(null);
    }}
    >
      <div>Location details</div>
    </InfoWindow>
  )}
  </GoogleMap>
  );
}

const WrappedMap = withScriptjs(withGoogleMap(Map)) ;

export default function App() {
  return (<div style= {{width: '100vw', height: '100vh'}}> 
      <WrappedMap 
      googleMapURL={'https://maps.googleapis.com/maps/api/js?v=3.exp&libraries=geometry,drawing,places&key=AIzaSyDGSRctysRXdR4pEh9F-r-ZXjTKtoAcKak'}
      loadingElement = {<div style = {{height: "100%"}}/>}
      containerElement = {<div style = {{height: "100%"}}/>}
      mapElement = {<div style = {{height: "100%"}}/>}
      /> 
      </div>
  );
};
